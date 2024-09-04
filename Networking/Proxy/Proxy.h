#pragma once
#include "ProxyConnection.h"
#include "../Http/HttpDiscoveryClient.h"
#include <algorithm>
#include <mutex>

class Proxy
{
private:
    asio::io_context context;
    std::thread contextThread;
    asio::ip::tcp::acceptor acceptor;
    uint16_t port;
    std::vector<std::unique_ptr<ProxyConnection>> proxyConnections;
    std::mutex proxyConnectionsMutex;
    std::shared_ptr<asio::io_context> tempContext;
    std::unique_ptr<asio::ip::tcp::socket> tempClientSocket;
    std::unique_ptr<asio::ip::tcp::socket> tempServerSocket;
    HttpDiscoveryClient httpClient;

    void waitForClientConnections()
    {
        tempContext = std::make_shared<asio::io_context>();
        tempClientSocket = std::make_unique<asio::ip::tcp::socket>(*tempContext);
        acceptor.async_accept(*tempClientSocket,
            [this](const std::error_code& ec)
            {
                if (!ec)
                {
                    std::cout << "New client connection : " << tempClientSocket->remote_endpoint() << "\n";

                    HttpDiscoveryClient::DarkServerInfo serverInfo = httpClient.getServerRequest();

                    std::cout << "Connecting client to : " << serverInfo.ip << ":" << serverInfo.port << "\n";

                    asio::ip::tcp::resolver resolver(context);
                    auto endpoints = resolver.resolve(serverInfo.ip, serverInfo.port);

                    tempServerSocket = std::make_unique<asio::ip::tcp::socket>(*tempContext);
                    asio::async_connect(*tempServerSocket, endpoints,
                        [this](const std::error_code& ec, const asio::ip::tcp::endpoint& endpoint) mutable
                        {
                            if (!ec)
                            {
                                std::cout << "New server connection : " << tempServerSocket->remote_endpoint() << "\n";

                                std::lock_guard lock(proxyConnectionsMutex);
                                proxyConnections.emplace_back(ProxyConnection::create(tempContext, std::move(tempClientSocket), std::move(tempServerSocket)));
                            }
                            else
                            {
                                std::cerr << "New server connection error : " << ec.message() << "\n";
                            }
                            tempContext.reset();
                            tempClientSocket.reset();
                            tempServerSocket.reset();
                            waitForClientConnections();
                        }
                    );
                    // Run to execute async_connect
                    tempContext->run();
                }
                else
                {
                    std::cerr << "New client connection error : " << ec.message() << "\n";
                    tempContext.reset();
                    tempClientSocket.reset();
                    waitForClientConnections();
                }
            }
        );
    }
public:
    Proxy(const uint16_t& port) : acceptor(context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)), httpClient(context)
    {
        this->port = port;
    }

    void start()
    {
        try
        {
            waitForClientConnections();

            contextThread = std::thread([this]() { context.run(); });
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        std::cout << "Server started on port [" << port << "].\n";
    }

    void stop()
    {
        context.stop();

        if (contextThread.joinable())
            contextThread.join();
    }

    void update()
    {
        std::lock_guard lock(proxyConnectionsMutex);
        for (std::unique_ptr<ProxyConnection>& proxyConnection : proxyConnections)
        {
            if (proxyConnection != nullptr)
            {
                if (proxyConnection->isConnected())
                {
                    proxyConnection->update();
                }
                else
                {
                    proxyConnections.erase(std::remove(proxyConnections.begin(), proxyConnections.end(), proxyConnection), proxyConnections.end());
                    std::cout << "Client disconnected.\n";
                }
            }
        }
    }
};