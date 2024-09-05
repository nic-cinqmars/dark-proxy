#pragma once
#include <asio.hpp>

class HttpDiscoveryClient
{
private:
    asio::io_context& context;
    asio::ip::tcp::socket socket;
    std::string message;
    std::string receivedMessage;

    const std::string getServerRequestMessage() const;

public:
    struct DarkServerInfo
    {
        std::string ip;
        std::string port;
    };

    HttpDiscoveryClient(asio::io_context& context) : context(context), socket(context)
    {
    }

    const DarkServerInfo getServerRequest();
};