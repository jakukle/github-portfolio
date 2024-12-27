#include "Client.h"
#include "Frame.h"
#include "BinFile.h"
#include <iostream>
#include "asio.hpp"

void Client::Echo(const std::string text, const asio::ip::address_v4 address, uint16_t port)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket(io_service);
	Frame frame;

	frame.type = Frame::Type::ECHO;
	frame.len = text.size();
	memcpy(frame.data, text.data(), text.length());

	std::cout << "Client: Connect to server " << address.to_string() << ":" << port << "\n";
	socket.connect(asio::ip::tcp::endpoint(address, port));
	std::cout << "Client: Send " << text.size() << " bytes of text data" << "\n";
	asio::write(socket, asio::buffer(&frame, sizeof(Frame)));

	asio::read(socket, asio::buffer(&frame, sizeof(Frame)));
	std::cout << "Client: Received response : " << std::string((const char*)frame.data, frame.len) << "\n";
	socket.close();
}

void Client::SendText(const std::string text, const asio::ip::address_v4 address, uint16_t port)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket(io_service);
	Frame frame;

	frame.type = Frame::Type::TEXT;
	frame.len = text.size();
	memcpy(frame.data, text.data(), text.length());

	std::cout << "Client: Connect to server " << address.to_string() << ":" << port << "\n";
	socket.connect(asio::ip::tcp::endpoint(address, port));
	std::cout << "Client: Send " << text.size() << " bytes of text data" << "\n";
	asio::write(socket, asio::buffer(&frame, sizeof(Frame)));
	socket.close();
}

bool Client::RecvFile(const std::string readFilename, const std::string writeFilename, const asio::ip::address_v4 address, uint16_t port)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket(io_service);
	Frame frame;

	frame.type = Frame::Type::RECV_FILE;
	memcpy(frame.data, readFilename.data(), readFilename.size());
	frame.len = readFilename.size();
	socket.connect(asio::ip::tcp::endpoint(address, port));
	asio::write(socket, asio::buffer(&frame, sizeof(Frame)));

	BinFile file(writeFilename, true);
	do {
		asio::read(socket, asio::buffer(&frame, sizeof(Frame)));
		if (frame.type == Frame::Type::FILE_DATA) {
			file.Append(frame.data, frame.len);
		}
	} while (frame.type == Frame::Type::FILE_DATA);
	if (frame.type == Frame::Type::END_OF_FILE)
	{
        std::cout << "Client: otrzymano plik" << std::endl;
		return true;
	}
	else
		return false;
}


bool Client::SendFile(const std::string readFilename, const std::string writeFilename, const asio::ip::address_v4 address, uint16_t port)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket(io_service);
	BinFile file(readFilename,  false);

	Frame frame;
	frame.type = Frame::Type::SEND_FILE;
	memcpy(frame.data, writeFilename.data(), writeFilename.length());
	frame.len = writeFilename.size();
	socket.connect(asio::ip::tcp::endpoint(address, port));
	asio::write(socket, asio::buffer(&frame, sizeof(Frame)));

	while (size_t len = file.Read(frame.data, FRAME_DATA_LEN)) {
		frame.type = Frame::Type::FILE_DATA;
		frame.len = len;
		asio::write(socket, asio::buffer(&frame, sizeof(Frame)));
	}
	frame.type = Frame::Type::END_OF_FILE;
	frame.len = 0;
	asio::write(socket, asio::buffer(&frame, sizeof(Frame)));
	if (file.IsOpen())
	{
	std::cout << "Client: otwarto plik" << std::endl;
	return true;
	}
	else
	return false;
}

Client::Client()
{
}

Client::~Client()
{
}
