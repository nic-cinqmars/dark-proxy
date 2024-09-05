#pragma once
#include <memory>
#include <iostream>
#include <asio.hpp>
#include "packet.h"
#include "thread_safe_queue.h"

class TcpConnection
{
private:
	std::shared_ptr<asio::io_context> context;
	std::unique_ptr<asio::ip::tcp::socket> socket;
	std::string message;
	ThreadSafeQueue<Packet> outgoingPackets;
	ThreadSafeQueue<Packet>& incomingPackets;
	Packet tempPacket;

	TcpConnection(std::shared_ptr<asio::io_context> context, std::unique_ptr<asio::ip::tcp::socket> socket, 
		ThreadSafeQueue<Packet>& incomingPackets) : context(std::move(context)), socket(std::move(socket)), incomingPackets(incomingPackets)
	{

	}

	void writeNextPacket();
	void readNextPacket();

public:
	static std::unique_ptr<TcpConnection> create(std::shared_ptr<asio::io_context> context, 
		std::unique_ptr<asio::ip::tcp::socket> socket, ThreadSafeQueue<Packet>& incomingPackets)
	{
		return std::unique_ptr<TcpConnection>(new TcpConnection(std::move(context), std::move(socket), incomingPackets));
	}

	void disconnect()
	{
		if (isConnected())
		{
			asio::post(*context, 
				[this]()
				{
					socket->close();
				}
			);
		}
	}

	bool isConnected() const
	{
		return socket->is_open();
	}

	void sendPacket(const Packet& packet);

	void startReading()
	{
		if (socket->is_open())
		{
			readNextPacket();
		}
	}
};