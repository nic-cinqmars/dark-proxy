#pragma once
#include <string>
#include <asio.hpp>

using asio::ip::tcp;

class HttpDiscoveryServer
{
public:
    HttpDiscoveryServer(uint16_t port, const std::string& darkServerIp, const uint16_t& darkServerPort);

private:
    void startAccept(const std::string& darkServerIp, const uint16_t& darkServerPort);

    asio::io_context context;
    std::thread contextThread;
    tcp::acceptor acceptor;
};