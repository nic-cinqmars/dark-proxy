#pragma once
#include <memory>
#include <thread>
#include <asio.hpp>
#include "thread_safe_queue.h"
#include "packet.h"
#include "tcp_connection.h"

class ProxyConnection
{
private:
    std::unique_ptr<TcpConnection> clientConnection;
    ThreadSafeQueue<Packet> incomingClientPackets;

    std::unique_ptr<TcpConnection> serverConnection;
    ThreadSafeQueue<Packet> incomingServerPackets;

    std::shared_ptr<asio::io_context> context;
    std::thread contextThread;

    ProxyConnection(std::shared_ptr<asio::io_context> context,
        std::unique_ptr<asio::ip::tcp::socket> clientSocket,
        std::unique_ptr<asio::ip::tcp::socket> serverSocket);

    void onClientPacket(const Packet& packet);
    void onServerPacket(const Packet& packet);

public:
	static std::unique_ptr<ProxyConnection> create(std::shared_ptr<asio::io_context> context, 
        std::unique_ptr<asio::ip::tcp::socket> clientSocket, std::unique_ptr<asio::ip::tcp::socket> serverSocket)
	{
		return std::unique_ptr<ProxyConnection>(new ProxyConnection(context, std::move(clientSocket), std::move(serverSocket)));
	}

    ~ProxyConnection()
    {
        clientConnection->disconnect();
        serverConnection->disconnect();

        context->stop();

        if (contextThread.joinable())
            contextThread.join();
    }

    void update()
    {
        if (isConnected())
        {
            if (!incomingClientPackets.empty())
            {
                onClientPacket(incomingClientPackets.pop_front());
            }

            if (!incomingServerPackets.empty())
            {
                onServerPacket(incomingServerPackets.pop_front());
            }
        }
    }

    bool isConnected()
    {
        if (clientConnection == nullptr || serverConnection == nullptr)
            return false;
        return clientConnection->isConnected() && serverConnection->isConnected();
    }

    void sendPacketToServer(const Packet& packet)
    {
        serverConnection->sendPacket(packet);
    }

    void sendPacketToClient(const Packet& packet)
    {
        clientConnection->sendPacket(packet);
    }
};