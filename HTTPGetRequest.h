#pragma once

#include <string>

#include <boost/asio.hpp>
typedef void(*HTTPRequestDataReceived)(char*, size_t);
typedef void(*HTTPRequestComplete)();

class HTTPGetRequest
{
public:
	HTTPGetRequest(
		boost::asio::io_service& io_service,
		std::string host,
		std::string relativeURL,
		HTTPRequestDataReceived receivedCB,
		HTTPRequestComplete completeCB);

	~HTTPGetRequest();

	void sendRequest();

private:
	HTTPRequestDataReceived m_receivedCB;
	HTTPRequestComplete m_completeCB;

	std::string m_host;
	std::string m_relativeURL;

	boost::asio::ip::tcp::socket m_socket;
	boost::asio::io_service& m_io_service;
	boost::asio::ip::tcp::resolver m_resolver;

	boost::asio::streambuf m_request;
	boost::asio::streambuf m_response;

	void ReadData();
};