#pragma once
#include <memory>
#include <string>
#include <asio.hpp>
#include <iostream>
#include "Packet.h"
#include "ThreadSafeQueue.h"

class TcpConnection
{
private:
	TcpConnection(std::shared_ptr<asio::io_context> context, std::unique_ptr<asio::ip::tcp::socket> socket, ThreadSafeQueue<Packet>& incomingPackets) 
	: context(std::move(context)), socket(std::move(socket)), incomingPackets(incomingPackets)
	{

	}

	std::shared_ptr<asio::io_context> context;
	std::unique_ptr<asio::ip::tcp::socket> socket;
	std::string message;
	ThreadSafeQueue<Packet> outgoingPackets;
	ThreadSafeQueue<Packet>& incomingPackets;
	Packet tempPacket;

	void writeNextPacket()
	{
		std::vector<asio::const_buffer> data = {
			asio::buffer(&outgoingPackets.front().header, sizeof(PacketHeader)),
		};

		if (outgoingPackets.front().header.length > sizeof(PacketHeader))
			data.push_back(asio::buffer(outgoingPackets.front().message.data(), outgoingPackets.front().message.size()));
		
		asio::async_write(*socket, data,
			[this](std::error_code ec, std::size_t length)
			{
				if (!ec)
				{
					outgoingPackets.pop_front();

					if (!outgoingPackets.empty())
						writeNextPacket();
				}
				else
				{
					std::cout << "Failed to write packet : " << ec.message() << ".\n";
					socket->close();
				}
			}
		);
	}

	void readNextPacket()
	{
		asio::async_read(*socket, asio::buffer(&tempPacket.header, sizeof(PacketHeader)),
			[this](std::error_code ec, std::size_t length)
			{
				if (!ec)
				{
					if (tempPacket.header.length > sizeof(PacketHeader))
					{
						tempPacket.message.resize(tempPacket.header.length - sizeof(PacketHeader));

						asio::async_read(*socket, asio::buffer(tempPacket.message.data(), tempPacket.message.size()),
							[this](std::error_code ec, std::size_t length)
							{
								if (!ec)
								{
									incomingPackets.push_back(tempPacket);

									readNextPacket();
								}
								else
								{
									std::cout << "Failed to read packet body : " << ec.message() << ".\n";
									socket->close();
								}
							}
						);
					}
					else
					{
						tempPacket.message.clear();
						incomingPackets.push_back(tempPacket);
						readNextPacket();
					}
				}
				else
				{
					std::cout << "Failed to read packet header : " << ec.message() << ".\n";
					socket->close();
				}
			}
		);
	}

public:
	static std::unique_ptr<TcpConnection> create(std::shared_ptr<asio::io_context> context, std::unique_ptr<asio::ip::tcp::socket> socket, ThreadSafeQueue<Packet>& incomingPackets)
	{
		return std::unique_ptr<TcpConnection>(new TcpConnection(std::move(context), std::move(socket), incomingPackets));
	}

	void connectToServer(const asio::ip::tcp::resolver::results_type& endpoints)
	{
		try
		{
			asio::connect(*socket, endpoints);
			std::cout << "Client connected!\n";
			startReading();
		}
		catch(const std::exception& e)
		{
			throw;
		}
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

	void sendPacket(const Packet& packet)
	{
		asio::post(*context,
			[this, packet]()
			{
				bool alreadyWritingMessage = !outgoingPackets.empty();
				outgoingPackets.push_back(packet);
				
				if (!alreadyWritingMessage)
				{
					writeNextPacket();
				}
			}
		);
	}

	void startReading()
	{
		if (socket->is_open())
		{
			readNextPacket();
		}
	}
};