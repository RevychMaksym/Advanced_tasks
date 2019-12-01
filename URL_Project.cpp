#include <vector>

#include <boost/asio.hpp>

#include "HTTPGetRequest.h"

std::vector<char> g_data;

void OnDataReceived(char* data, size_t dataLen)
{
	unsigned oldSize = g_data.size();
	g_data.resize(oldSize + dataLen);
	memcpy(&g_data[oldSize], data, dataLen);
}

void OnRequestCompleted()
{
	g_data.push_back('\0');
	printf(&g_data[0]);
}

int main(int argc, char** argv[])
{
	boost::asio::io_service io_service;

	HTTPGetRequest req(
		io_service,
		"www.google.com",
		"/index.html",
		OnDataReceived,
		OnRequestCompleted);

	req.sendRequest();

	io_service.run();

	return 0;
}