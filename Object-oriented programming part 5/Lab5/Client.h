#pragma once
#include "asio.hpp"
class Client
{
public:
	Client();
	virtual ~Client();
	void Echo(const std::string text, const asio::ip::address_v4 address, uint16_t port);
	void SendText(const std::string, const asio::ip::address_v4, uint16_t);
	bool RecvFile(const std::string readFilename, const std::string writeFilename, const asio::ip::address_v4 address, uint16_t port);
	bool SendFile(const std::string readFilename, const std::string writeFilename, const asio::ip::address_v4 address, uint16_t port);
	
};


