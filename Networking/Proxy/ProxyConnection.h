#pragma once
#include "TcpConnection.h"
#include <_PacketCommand.pb.h>
#include <Common.pb.h>
#include <Account.pb.h>
#include <_Chat.pb.h>
#include <_Character.pb.h>

using namespace DC::Packet;

class ProxyConnection
{
private:
    std::unique_ptr<TcpConnection> clientConnection;
    ThreadSafeQueue<Packet> incomingClientPackets;

    std::unique_ptr<TcpConnection> serverConnection;
    ThreadSafeQueue<Packet> incomingServerPackets;

    std::shared_ptr<asio::io_context> context;
    std::thread contextThread;

    ProxyConnection(std::shared_ptr<asio::io_context> context, std::unique_ptr<asio::ip::tcp::socket> clientSocket, std::unique_ptr<asio::ip::tcp::socket> serverSocket) : context(std::move(context))
    {
        std::cout << "New proxy connection\n";
        clientConnection = TcpConnection::create(this->context, std::move(clientSocket), incomingClientPackets);
        serverConnection = TcpConnection::create(this->context, std::move(serverSocket), incomingServerPackets);

        contextThread = std::thread([this]() { this->context->run(); });

        clientConnection->startReading();
        serverConnection->startReading();
    }

    void onClientPacket(const Packet& packet)
    {
        PacketCommand packetType = PacketCommand(packet.header.id);
        std::cout << "Received [" << PacketCommand_Name(packetType) << "] packet from client : \n";

        const google::protobuf::Descriptor* desc = google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName("DC.Packet.S" + PacketCommand_Name(packetType));
        if (desc != nullptr)
        {
            google::protobuf::Message* message = google::protobuf::MessageFactory::generated_factory()->GetPrototype(desc)->New();
            message->ParseFromArray(packet.message.data(), packet.message.size());

            std::cout << message->DebugString();

            delete message;

        }

        serverConnection->sendPacket(packet);
    }

    void onServerPacket(const Packet& packet)
    {
        PacketCommand packetType = PacketCommand(packet.header.id);
        std::cout << "Received [" << PacketCommand_Name(packetType) << "] packet from server :\n";

        const google::protobuf::Descriptor* desc = google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName("DC.Packet.S" + PacketCommand_Name(packetType));
        if (desc != nullptr)
        {
            google::protobuf::Message* message = google::protobuf::MessageFactory::generated_factory()->GetPrototype(desc)->New();
            message->ParseFromArray(packet.message.data(), packet.message.size());

            std::cout << message->DebugString();

            delete message;
        }

        switch (packetType)
        {
            case S2C_LOBBY_ENTER_RES:
                SS2C_WHISPER_CHAT_NOT chatNotification;
                chatNotification.mutable_chatdata()->set_accountid("Dark-Proxy");
                chatNotification.mutable_chatdata()->set_characterid("Dark-Proxy");
                chatNotification.mutable_chatdata()->mutable_nickname()->set_originalnickname("Dark-Proxy");
                chatNotification.mutable_chatdata()->mutable_nickname()->set_streamingmodenickname("Dark-Proxy");
                chatNotification.mutable_chatdata()->mutable_nickname()->set_karmarating(0);
                chatNotification.mutable_chatdata()->mutable_nickname()->set_rankid("Dark-Proxy");
                chatNotification.mutable_chatdata()->mutable_nickname()->set_fame(0);
                chatNotification.mutable_chatdata()->set_partyid("Dark-Proxy");
                SCHATDATA_PIECE piece;
                piece.set_chatstr("Connected to Dark-Proxy!");
                chatNotification.mutable_chatdata()->mutable_chatdatapiecearray()->Add(std::move(piece));

                Packet chatNotificationPacket;
                chatNotificationPacket.header.id = S2C_WHISPER_CHAT_NOT;
                chatNotificationPacket << chatNotification.SerializeAsString();
                clientConnection->sendPacket(chatNotificationPacket);
                break;
        }

        clientConnection->sendPacket(packet);
    }

public:
	static std::unique_ptr<ProxyConnection> create(std::shared_ptr<asio::io_context> context, std::unique_ptr<asio::ip::tcp::socket> clientSocket, std::unique_ptr<asio::ip::tcp::socket> serverSocket)
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