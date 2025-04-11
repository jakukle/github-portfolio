// Aiut - Jakub Klepacz - Version 1.0 - 21.03.2025

#include "DistanceFun_ColorScaling_Jakub.h"

float const dist_range_min_value = 0.1, dist_range_max_value = 1.2, dist_range_step_value = 0.01;

float get_dist_range_max_value() {
	return dist_range_max_value;
}

void DistanceZ_sorting(std::vector<visionary::PointXYZ>& validElements_sorted, std::vector<visionary::PointXYZ> pointCloud) {
	
	std::vector<visionary::PointXYZ> validElements; // correct z value vector
	
													// A loop that iterates through all the elements of a vector
	for (const auto& elem : pointCloud)
		if (!std::isnan(elem.z))
			validElements.push_back(elem); // we only add elements with correct z
			// Sorting the validElements vector by value z
	std::sort(validElements.begin(), validElements.end(), [](const visionary::PointXYZ& a, const visionary::PointXYZ& b) {
		return a.z < b.z; // comparison ascending by z
	});
	
	// Number of elements in each compartment
	std::map<std::pair<float, float>, int> rangeCounts;
	
	// Definition of ranges between min & max distance
	for (float start = dist_range_min_value; start < dist_range_max_value; start += dist_range_step_value) {
		float end = start + dist_range_step_value;
		rangeCounts[{start, end}] = 0; // init the counter
	}
	
	// Counting elements in ranges
	for (const auto& elem : validElements)
		for (float start = dist_range_min_value; start < dist_range_max_value; start += dist_range_step_value) {
			float end = start + dist_range_step_value;
			if (elem.z >= start && elem.z < end) {
				rangeCounts[{start, end}]++;
				break; // one point belongs to only one interval
			}
		}
	
	validElements_sorted = validElements;
}

void DistanceZ_colors(const std::vector<visionary::PointXYZ>& validElements_sorted, int pixel_cm, 
	cv::Mat& image_out, const std::uint32_t height, const std::uint32_t width) {

	// Range error
	if (dist_range_min_value >= dist_range_max_value) {
		std::cerr << "\033[33m" << "Warning: Incorrect minimum and maximum distance values!" << "\033[0m" << std::endl;
		return;
	}

	// Create image
	cv::Mat image (height, width, CV_8UC3, cv::Scalar(255,255,255));

	// Maximum target dimensions
	const int MAX_WIDTH = 512;
	const int MAX_HEIGHT = 424;

	// Finding minimum and maximum values for x and y
	float x_min = std::numeric_limits<float>::max();
	float x_max = std::numeric_limits<float>::lowest();
	float y_min = std::numeric_limits<float>::max();
	float y_max = std::numeric_limits<float>::lowest();

	for (const auto& point : validElements_sorted) {
		x_min = std::min(x_min, point.x);
		x_max = std::max(x_max, point.x);
		y_min = std::min(y_min, point.y);
		y_max = std::max(y_max, point.y);
	}

	// Iterating through points and drawing them on the image
	for (const auto& point : validElements_sorted) {
		// Ignoring points outside the range of
		if (point.z < dist_range_min_value || point.z > dist_range_max_value) {
			continue;
		}

		// Normalizing z values ​​to 0-1 range
		float normalizedZ = (point.z - dist_range_min_value) / (dist_range_max_value - dist_range_min_value);

		// Converting from z-value to HSV color space
		float hue = normalizedZ * 240.0f; // from red to blue
		float saturation = 128.0f + (1.0f - normalizedZ) * 127.0f; // from more intensity to less intensity
		float brightness = 128 + (1.0f - normalizedZ) * 127.0f; // from more brightness to less brightness
		cv::Mat hsvColor(1, 1, CV_8UC3, cv::Scalar(hue, saturation, brightness)); // HSV: Hue, Saturation ("Intensity"), Value/Brightness
		cv::Mat rgbColor;
		cv::cvtColor(hsvColor, rgbColor, cv::COLOR_HSV2BGR); // Conversion from HSV to RGB

		// Getting RGB values ​​from matrix
		cv::Vec3b color = rgbColor.at<cv::Vec3b>(0, 0);

		// Rescaling x and y to the image size
		float scaledX = width - (((point.x - x_min) / (x_max - x_min)) * width);
		float scaledY = height - (((point.y - y_min) / (y_max - y_min)) * height);

		// Making sure the scaled coordinates are within the image boundaries
		int x = static_cast<int>(scaledX);
		int y = static_cast<int>(scaledY);

		// Making sure the coordinates are within the image boundaries
		if (x >= 0 && x < width && y >= 0 && y < height) {
			//image.at<cv::Vec3b>(y, x) = color;
			cv::circle(image, cv::Point(x, y), 2, cv::Scalar(color[0], color[1], color[2]), -1); // Filled circle (-1)
		}
	}

	// Displaying in continuous_streaming
	cv::resize(image, image_out, cv::Size(MAX_WIDTH, MAX_HEIGHT), 0, 0, cv::INTER_LINEAR);
}