#pragma once
#include <thread>
#include <vector>
#include <mutex>
#include <asio.hpp>
#include <memory>

class ProxyConnection;
class HttpDiscoveryClient;

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
    std::unique_ptr<HttpDiscoveryClient> httpClient;

    void waitForClientConnections();
public:
    Proxy(const uint16_t& port);
    ~Proxy();

    void start();

    void stop()
    {
        context.stop();

        if (contextThread.joinable())
            contextThread.join();
    }

    void update();
};