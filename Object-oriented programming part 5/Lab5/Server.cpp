#include <iostream>
#include "Server.h"
#include "asio.hpp"
#include"Frame.h"
#include"BinFile.h"



void session(asio::ip::tcp::socket socket){
	try
	{
		while(true){
			Frame rFrame;
			Frame sFrame;
			asio::read(socket, asio::buffer(&rFrame, sizeof(Frame)));
			
			switch (rFrame.type) {
			case Frame::Type::ECHO:
				std::cout << "Session: robi ECHO..." << std::endl;
				asio::write(socket, asio::buffer(&rFrame, sizeof(Frame)));
				break;

			case Frame::Type::TEXT:
				std::cout << "Session: odbiera TEXT..." << std::string((const char*)rFrame.data, rFrame.len) << std::endl;
				break;

			case Frame::Type::SEND_FILE:
			{
				BinFile file(std::string((const char*)rFrame.data, rFrame.len), true);

				do {
					asio::read(socket, asio::buffer(&rFrame, sizeof(Frame)));
					if (rFrame.type == Frame::Type::FILE_DATA) {
						file.Append(rFrame.data, rFrame.len);
					}
				} while (rFrame.type == Frame::Type::FILE_DATA);

				std::cout << "Session: otrzymano plik" << std::endl;
			}
			break;

			case Frame::Type::RECV_FILE:
			{
				BinFile file(std::string((const char*)rFrame.data, rFrame.len), false);

				while (size_t len = file.Read(sFrame.data, FRAME_DATA_LEN)){
					sFrame.type = Frame::Type::FILE_DATA;
					sFrame.len = len;
					asio::write(socket, asio::buffer(&sFrame, sizeof(Frame)));
					
					if (len == 0) {
                        sFrame.type = Frame::Type::END_OF_FILE;
					}
				}
				std::cout << "Session: wsy³ano plik" << std::endl;
				
			}
				break;

			default:
				sFrame.type = Frame::Type::INVALID_COMMAND;
				sFrame.len = 0;
				asio::write(socket, asio::buffer(&sFrame, sizeof(Frame)));
				break;
			}
		}
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception in thread: " << e.what() << "\n";
	}
	socket.close();
}


void Server::ThreadRoutine()
{
	asio::io_service io_service; // Any program that uses asio need to have at least one io_service object
	asio::ip::tcp::acceptor acceptor(io_service, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)); //create acceptor for listening purposes
	acceptor.listen(1024);
	while (IsRunning())
	{
		asio::ip::tcp::socket socket(io_service); //create a socket for communication purposes
		acceptor.accept(socket); //then accept connection
		
		//read data sent by the client, then send echo
		std::thread(session, std::move(socket)).detach();

		std::this_thread::yield();
	}
}

Server::Server(unsigned short port) : port(port)
{
}



Server::~Server()
{
}

