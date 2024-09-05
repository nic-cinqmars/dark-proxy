#include "dark_networking/http_discovery_server.h"

#include <memory>
#include <iostream>
#include "http_discovery_connection.h"

HttpDiscoveryServer::HttpDiscoveryServer(uint16_t port, const std::string &darkServerIp, 
    const uint16_t &darkServerPort) : acceptor(context, tcp::endpoint(tcp::v4(), port))
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

void HttpDiscoveryServer::startAccept(const std::string& darkServerIp, const uint16_t& darkServerPort)
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