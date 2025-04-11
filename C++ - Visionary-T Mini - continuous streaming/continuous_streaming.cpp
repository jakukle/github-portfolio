//Aiut - Jakub Klepacz - Version 1.0 - 05.02.2025
//Aiut - Jakub Klepacz - Version 1.1 - 14.03.2025
//Aiut - Jakub Klepacz - Version 1.2 - 17.03.2025
//Aiut - Jakub Klepacz - Version 1.3 - 21.03.2025

#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>
#include <cassert>
#include <atomic> 
#include <csignal> 
#include <algorithm>
#include <limits>

#include <sick_visionary_cpp_base/FrameGrabber.h>
#include <sick_visionary_cpp_base/NetLink.h>
#include <sick_visionary_cpp_base/PointCloudPlyWriter.h>
#include <sick_visionary_cpp_base/PointXYZ.h>
#include <sick_visionary_cpp_base/VisionaryControl.h>
#include <sick_visionary_cpp_base/VisionaryType.h>

#include "BlobServerConfig.h"
#include "UdpParsing.h"
#include "exitcodes.h"
#include "framewrite.h"

#include "DBSCAN_Jakub.h"
#include "DistanceFun_ColorScaling_Jakub.h"

bool except_or_wrong_time = false;

// Atomic flag variable to control application termination
std::atomic<bool> stopFlag(false);

// Function handling the 'end' signal (e.g. Ctrl+C) 
void signalHandler(int signum) {
    std::cout << "\033[33m" << "Warning: Termination signal received (Ctrl+C), exiting safely..." << "\033[0m" << std::endl;
    stopFlag.store(true);  // Set the flag until the app is closed
}

static ExitCode runContinuousStreamingDemo(visionary::VisionaryType visionaryType,
                                           const std::string&       transportProtocol,
                                           const std::string&       ipAddress,
                                           const std::string&       receiverIp,
                                           std::uint16_t            streamingPort,
                                           unsigned                 numberOfFrames,
                                           const std::string&       filePrefix,
                                           bool                     storeData)
{ 
  using namespace visionary;
  std::shared_ptr<VisionaryControl> visionaryControl = std::make_shared<VisionaryControl>(visionaryType);

  // tag::open_control_channel[]
  if (!visionaryControl->open(ipAddress))
  {
	  std::fprintf(stderr, "Failed to open control connection to device.\n");
	  return ExitCode::eControlCommunicationError;
  }

  // Stop image acquisition (works always, also when already stopped). Further you should always stop the device before reconfiguring it.
  // tag::precautionary_stop[]
  if (!visionaryControl->stopAcquisition())
  {
	  std::fprintf(stderr, "Failed to stop acquisition.\n");
	  return ExitCode::eControlCommunicationError;
  }

  // Depending on the PC we might be too fast for the device configuration. Just wait a short time. This should only be necessary after stop
  // (to make sure stop really propagated and you don't get a pending frame) or after a configure to make sure configuration has finished
  // tag::precautionary_stop[]
  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  // Login to the device for access rights to certain methods
  visionaryControl->login(IAuthentication::UserLevel::SERVICE, "CUST_SERV");
  std::shared_ptr<visionary::NetLink> udpSocket;

  // tag::udp_settings[]
 if (transportProtocol == "UDP")
  {
    // streaming settings
    setTransportProtocol(visionaryControl, transportProtocol);
	setBlobUdpAutoTransmit(visionaryControl, true);
	setBlobUdpReceiverIP(visionaryControl, receiverIp);
    setBlobUdpReceiverPort(visionaryControl, streamingPort);
	setBlobUdpControlPort(visionaryControl, streamingPort);
	setBlobUdpHeartbeatInterval(visionaryControl, 0);
    setBlobUdpMaxPacketSize(visionaryControl, 1024);
    setBlobUdpIdleTimeBetweenPackets(visionaryControl, 10); // in microseconds
    setBlobUdpHeaderEnabled(visionaryControl, true);
    setBlobUdpFecEnabled(visionaryControl, false); // forward error correction

    // Open the datagram socket -> Create a new UdpSocket object
    // Prefix 24 assumption -> problem: 192.168.136.100/16 valid device IP 192.168.136.255 in this case socket will be
    // in broadcast mode using prefix 0 -> netmask 0.0.0.0 only broadcast = global broadcast 255.255.255.255 - OK
	udpSocket = std::make_shared<visionary::NetLink>(receiverIp, 24, streamingPort, ipAddress);
  }
  // end::udp_settings[]

  // login / logout always need to form blocks because login chnages to config mode (no streaming active) and logout returns to RUN mode (streaming)
  visionaryControl->logout();

  std::shared_ptr<VisionaryData>    pDataHandler  = nullptr;
  auto start = std::chrono::steady_clock::now();// var for start counting a time
  std::chrono::duration<double, std::milli> elapsed_max (std::numeric_limits<double>::min());
  std::chrono::duration<double, std::milli> elapsed_min (std::numeric_limits<double>::max());
  std::chrono::duration<double, std::milli> elapsed;
  auto end = std::chrono::steady_clock::now(); // var for stop counting a time
  bool except = false;
  int64_t min_time_program = 10;
  int64_t rest_time = 248;
  long long time_us_prev_one_cycle = 0, time_difference_one_cycle = 0, time_difference_sum = 0, 
	  time_difference_mean = 0, time_difference_delta = 0, cycle_counter = 1;
#ifdef _DEBUG
  rest_time = 1000;
  int counts = 0; //each 10 frames stop/start acquisition
  int counts_max = 10;
#endif

  // tag::start_acquisition[]
  if (!visionaryControl->startAcquisition())
  {
	  std::fprintf(stderr, "Failed to start acquisition.\n");
	  return ExitCode::eControlCommunicationError;
  }

  //-----------------------------------------------// Start the image acquisition and continuously receive frames

  while (!stopFlag.load())
  {
	start = std::chrono::steady_clock::now();

#ifdef _DEBUG
	counts++;
	if (counts == counts_max+1) {

		if (!visionaryControl->startAcquisition())
		{
			std::fprintf(stderr, "Failed to start acquisition.\n");
			return ExitCode::eControlCommunicationError;
		}
		counts = 1;
	}
#endif

    // tag::udp_acquisition[]
    pDataHandler = visionaryControl->createDataHandler();
    std::map<std::uint16_t, ITransport::ByteBuffer> fragmentMap;
    ITransport::ByteBuffer                          buffer;
	int                                             received;
	std::size_t                                     maxBytesToReceive = 1024;
	std::uint16_t                                   lastFrameNum      = 0;

    // Receive from UDP Socket
    buffer.resize(maxBytesToReceive);
    received = udpSocket->read(buffer);
    std::cout << "\n\n========== new BLOB received ==========" << "\n";
    std::cout << "Blob number: " << ((buffer[0] << 8) | buffer[1]) << "\n";
    std::cout << "server IP: " << ipAddress << "\n";
    std::cout << "========================================" << "\n";
	// FIN Flag of Statemap in header is set when new BLOB begins
    while (buffer[6] != 0x80)
    {
		std::uint16_t fragmentNumber = (static_cast<std::uint16_t>(buffer[2]) << 8) | buffer[3];
        if (fragmentNumber - lastFrameNum > 1)
        printf("Lost %d frames between Frames: %d %d \n", fragmentNumber - lastFrameNum, lastFrameNum, fragmentNumber);
        lastFrameNum = fragmentNumber;
		// Payload begins at byteindex 14, Last element contains checksum
        ITransport::ByteBuffer fragment(buffer.begin() + 14, buffer.end() - 1); 
        fragmentMap[fragmentNumber] = fragment;
        received                    = udpSocket->read(buffer);
	}
    int                    fragmentNumber = (buffer[2] << 8) | buffer[3];
    ITransport::ByteBuffer last_fragment(buffer.begin() + 14, buffer.end() - 1);
    fragmentMap[fragmentNumber] = last_fragment;
    auto completeBlob = reassembleFragments(fragmentMap);
    visionary::parseUdpBlob(completeBlob, pDataHandler);
    // end::udp_acquisition[]

    std::printf("Frame received in continuous mode, frame #%" PRIu32 "\n", pDataHandler->getFrameNum());

	// Variables for buffer validElements and for pointCloud;
	std::vector<PointXYZ> validElements_sorted, pointCloud;

	if (storeData)
	{
		try
		{
			// Write the frame to disc
			writeFrame(visionaryType, *pDataHandler, filePrefix);
			// Convert data to a point cloud
			pDataHandler->generatePointCloud(pointCloud);
			pDataHandler->transformPointCloud(pointCloud);

			// Write point cloud to PLY
			const std::string framePrefix  = std::to_string(pDataHandler->getFrameNum());
			std::string       plyFilePath  = /*framePrefix + */"aa-pointcloud.ply";
			const char*       cPlyFilePath = plyFilePath.c_str();
			std::printf("Writing one frame to %s\n", cPlyFilePath);

			PointCloudPlyWriter::WriteFormatPLY(cPlyFilePath, pointCloud, pDataHandler->getIntensityMap(), true);
			std::printf("Finished writing frame to %s\n", cPlyFilePath);
		}
		catch (const std::exception& e)  // Catch standard exceptions
		{
			except = true;
			std::cout << "\033[1;31m" << "EXCEPTION: Write the frame to disk failed\n" << "\033[0m";
			std::fprintf(stderr, "Exception caught: %s\n", e.what());
		}
	}

	// Get the width and height of the images
	const std::uint32_t Image_width = pDataHandler->getWidth(); //Same size as the "aaa" files written to the disc
	const std::uint32_t Image_height = pDataHandler->getHeight();

	// Get the system time in microseconds
	long long time_us_one_cycle = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	if (time_us_prev_one_cycle > 0) {
		time_difference_one_cycle = time_us_one_cycle - time_us_prev_one_cycle;
		time_difference_sum += time_difference_one_cycle;
		time_difference_mean = time_difference_sum / cycle_counter;
		time_difference_delta = time_difference_mean - rest_time * 1000;
		cycle_counter++;
		std::cout << "\033[1;36m" << "Time difference mean (us): " << time_difference_mean << "\033[0m\n";
	}
	time_us_prev_one_cycle = time_us_one_cycle;

	int const factor_range_scaling = -968;
	float dist_range_max_value = get_dist_range_max_value();
	int pixel_cm = factor_range_scaling / dist_range_max_value;
	cv::Mat DistanceZ_image_out(Image_height, Image_width, CV_8UC3, cv::Scalar(255, 255, 255));
	cv::Mat DBSCAN_image_out(Image_height, Image_width, CV_8UC3, cv::Scalar(255, 255, 255));

	//---------- FUNCTION TO DETECT OBJECTS BY "Z" COORDINATE ----------//  
	DistanceZ_sorting(validElements_sorted, pointCloud);
	std::thread thread_distance([&]() {
		try {
			DistanceZ_colors(validElements_sorted, pixel_cm, DistanceZ_image_out, Image_height, Image_width); // This fun and DBSCAN use validElements_sorted only in read mode - no mutex need
		}
		catch (const std::exception& e) {
			except = true;
			std::cout << "\033[1;31m" << "EXCEPTION: Function 'DistanceZ_colors' failed\n" << "\033[0m";
			std::fprintf(stderr, "Exception caught: %s\n", e.what());
		}
	});
	//---------- FUNCTION TO DETECT OBJECTS BY "Z" COORDINATE ----------//    

	//------------------- ALGORITM NO. 2 - DBSCAN --------------------//
	float eps = 0.008f; // Maximum distance between points in the same cluster (in meters) - default: 0.01f
	int min_samples = 35; // Minimum number of points to create a cluster - default: 2
	std::vector<int> labels; // A vector storing the assignment of points to clusters
	std::vector<visionary::PointXYZ> centroids; // Centroid's of clusters

	/*try {
		DBSCAN(validElements_sorted, eps, min_samples, labels, centroids, pixel_cm, DBSCAN_image_out, Image_height, Image_width);

		auto maxElement = std::max_element(labels.begin(), labels.end());
		if (maxElement != labels.end() && *maxElement != -2) // Making sure vector is not empty before dereferencing and not only noise found
			std::cout << "\033[1m" << "Amount of clusters: " << *maxElement << "\033[0m" << "\n";
	}
	catch (const std::exception& e) {
		except = true;
		std::cout << "\033[1;31m" << "EXCEPTION: Function 'DistanceZ_colors' failed\n" << "\033[0m";
		std::fprintf(stderr, "Exception caught: %s\n", e.what());
	}*/
	//------------------- ALGORITM NO. 2 - DBSCAN --------------------//

	// Waiting for thread
	thread_distance.join();

	//-------------------------- Displaying --------------------------//
	if (!except) {
		cv::imwrite("aaaa-Distance_SCALE.png", DistanceZ_image_out);
		std::cout << "Distance image saved as aaaa-Distance_SCALE.png" << std::endl;
		cv::imshow("Live stream - Distance", DistanceZ_image_out);
		cv::waitKey(1); // Wait 1 ms

		cv::imwrite("aaaa-Centroids_DBSCAN.png", DBSCAN_image_out);
		std::cout << "Centroids image saved as aaaa-Centroids_DBSCAN.png" << std::endl;
		cv::imshow("Last available clusters - DBSCAN", DBSCAN_image_out);
		cv::waitKey(1);
	}
	//-------------------------- Displaying --------------------------//

#ifdef _DEBUG
	if (counts == counts_max) {
		if (!visionaryControl->stopAcquisition())
		{
			std::fprintf(stderr, "Failed to stop acquisition.\n");
			return ExitCode::eControlCommunicationError;
		}
	}
#endif

	end = std::chrono::steady_clock::now();
	elapsed = end - start;
	if (elapsed > elapsed_max) elapsed_max = elapsed;
	std::cout << "\033[96m" << "Max time elapsed: " << elapsed_max.count() << "\033[0m" << std::endl;
	std::cout << "\033[1;96m" << "Time elapsed now: " << elapsed.count() << "\033[0m" << std::endl;
	if (elapsed < elapsed_min) elapsed_min = elapsed;
	std::cout << "\033[96m" << "Min time elapsed: " << elapsed_min.count() << "\033[0m" << std::endl;

	// Try to compensate for the cycle difference from the previous execution
	if (elapsed.count() < rest_time && elapsed.count() > min_time_program && !except)
		if (cycle_counter > 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(rest_time) - elapsed - std::chrono::microseconds(time_difference_delta));
			std::cout << "\033[36m" << "CYCLE TIME: " << time_difference_one_cycle/1000 << "   CYCLE NUMBER: " << cycle_counter <<"\033[0m" << std::endl;
		}
		else 
			std::this_thread::sleep_for(std::chrono::milliseconds(rest_time) - elapsed);
#ifdef _DEBUG
	else {
		if (counts != counts_max) {
		except_or_wrong_time = true;
		break;
		}
	}
#else
	else {
		except_or_wrong_time = true;
		break;
	}
#endif

  }

  //-----------------------------------------------//

  if (!visionaryControl->stopAcquisition())
  {
	  std::fprintf(stderr, "Failed to stop acquisition.\n");
	  return ExitCode::eControlCommunicationError;
  }

  // tag::close_control_channel[]
  visionaryControl->close();

  std::cout << "Close.\n";
  return ExitCode::eOk;
}



int main(int argc, char* argv[])
{
  std::string   deviceIpAddr{"192.168.0.49"};
  std::string   transportProtocol{"UDP"};
  std::string   receiverIp{"192.168.0.20"};
  std::string   filePrefix{""};
  std::uint16_t streamingPort = 2114;
  unsigned      cnt           = 20u;
  bool          storeData     = true;
  visionary::VisionaryType visionaryType(visionary::VisionaryType::eVisionaryTMini);

  bool showHelpAndExit = false;
  ExitCode exitCode = ExitCode::eOk;

   // Signal handler registration for Ctrl+C (SIGINT)
    signal(SIGINT, signalHandler);

  for (int i = 1; i < argc; ++i)
  {
    std::istringstream argstream(argv[i]);

    if (argstream.get() != '-')
    {
      showHelpAndExit = true;
      exitCode        = ExitCode::eParamError;
      break;
    }
    switch (argstream.get())
    {
      case 'h':
        showHelpAndExit = true;
        break;
      case 't':
        argstream >> transportProtocol;
        break;
      case 'i':
        argstream >> deviceIpAddr;
        break;
      case 'r':
        argstream >> receiverIp;
        break;
      case 'n':
        argstream >> cnt;
        break;
      case 'o':
        argstream >> filePrefix;
        break;
      case 's':
        argstream >> streamingPort;
        break;
      case 'd':
      {
        std::string visionaryTypeName;
        argstream >> visionaryTypeName;
        try
        {
          visionaryType = visionary::VisionaryType::fromString(visionaryTypeName);
        }
        catch (const std::invalid_argument& e)
        {
          // NOLINTNEXTLINE(performance-avoid-endl)
          std::cerr << e.what() << ": '" << visionaryTypeName << "'" << std::endl;
          showHelpAndExit = true;
          exitCode        = ExitCode::eParamError;
        }
      }
      break;
      case 'w':
      {
        std::string arg;
        argstream >> arg;
        storeData = (arg == "true" ? true : false);
      }
      break;
      default:
        showHelpAndExit = true;
        break;
    }
  }

  if (showHelpAndExit)
  {
    std::cout << "\nUsage: " << argv[0] << " [option]*\n";
    std::cout << "where option is one of:\n";
    std::cout << "  -h                          show this help and exit\n";
    std::cout << "  -t<transport protocol>      The transport protocol is UDP; default is also "
              << transportProtocol << '\n';
    std::cout << "  -i<IP>                      connect to the device with IP address <IP>; default is " << deviceIpAddr
              << '\n';
    std::cout << "  -r<receiver IP>             The IP address of the receiving PC (UDP only); default is "
              << receiverIp << '\n';
    std::cout << "  -s<streaming port>          The port of the data channel.; default is " << streamingPort << '\n';
    std::cout << "  -d<device type>             visionary product type is T-Mini; default is also '" << visionaryType.toString()
              << "'\n";
    std::cout << "  -n<cnt>                     acquire <cnt> frames and stop; default is " << cnt << '\n';
    std::cout << "  -o<file prefix>             prefix for the output files; default is '" << filePrefix << "'\n";
    std::cout << "  -w<write files>             write data to files if true; default is '"
              << (storeData ? "true" : "false") << "'\n";
    std::cout << "\nVisionary product types:\n";
    for (const auto& name : visionary::VisionaryType::getNames())
    {
      std::cout << "  " << name << '\n';
    }
    return static_cast<int>(exitCode);
  }

  back_to_acquisition:

  exitCode = runContinuousStreamingDemo(
    visionaryType, transportProtocol, deviceIpAddr, receiverIp, streamingPort, cnt, filePrefix, storeData);
  std::cout << "exit code " << static_cast<int>(exitCode) << '\n';
  if (except_or_wrong_time)
  {
	  std::cerr << "\033[1;31m" << "ERROR: Exception or time problem" << "\033[0m" << "\n";
	  except_or_wrong_time = false;
	  goto back_to_acquisition;
  }
  return static_cast<int>(exitCode);
}