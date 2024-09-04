#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <asio.hpp>
#include "HttpDiscoveryConnection.h"

using asio::ip::tcp;

class HttpDiscoveryServer
{
public:
    HttpDiscoveryServer(uint16_t port, const std::string& darkServerIp, const uint16_t& darkServerPort): acceptor(context, tcp::endpoint(tcp::v4(), port))
    {
        try
        {
            startAccept(darkServerIp, darkServerPort);

            contextThread = std::thread([this]() { context.run(); });
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        std::cout << "[HttpDiscovery] Server started on port [" << port << "]. Redirecting to [" << darkServerIp << ":" << darkServerPort << "]\n";
    }

private:
    void startAccept(const std::string& darkServerIp, const uint16_t& darkServerPort)
    {
        acceptor.async_accept(context,
            [this, darkServerIp, darkServerPort](const std::error_code& ec, asio::ip::tcp::socket socket)
            {
                if (!ec)
                {
                    std::cout << "[HttpDiscovery] Received connection.\n";
                    std::shared_ptr<HttpDiscoveryConnection> connection = HttpDiscoveryConnection::create(std::move(socket), darkServerIp, darkServerPort);
                    connection->start();
                }
                startAccept(darkServerIp, darkServerPort);
            }
        );
    }

    asio::io_context context;
    std::thread contextThread;
    tcp::acceptor acceptor;
};