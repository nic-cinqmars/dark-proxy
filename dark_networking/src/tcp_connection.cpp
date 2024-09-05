#include "tcp_connection.h"

void TcpConnection::writeNextPacket()
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

void TcpConnection::readNextPacket()
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

void TcpConnection::sendPacket(const Packet& packet)
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