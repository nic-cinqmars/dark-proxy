#include "proxy_connection.h"

#include <_PacketCommand.pb.h>
#include <Common.pb.h>
#include <Account.pb.h>
#include <_Chat.pb.h>
#include <_Character.pb.h>
#include <Merchant.pb.h>
#include <InGame.pb.h>

using namespace DC::Packet;

ProxyConnection::ProxyConnection(std::shared_ptr<asio::io_context> context, 
    std::unique_ptr<asio::ip::tcp::socket> clientSocket, std::unique_ptr<asio::ip::tcp::socket> serverSocket) : 
    context(std::move(context))
{
    std::cout << "New proxy connection\n";
    clientConnection = TcpConnection::create(this->context, std::move(clientSocket), incomingClientPackets);
    serverConnection = TcpConnection::create(this->context, std::move(serverSocket), incomingServerPackets);

    contextThread = std::thread([this]() { this->context->run(); });

    clientConnection->startReading();
    serverConnection->startReading();
}

void ProxyConnection::onClientPacket(const Packet& packet)
{
    PacketCommand packetType = PacketCommand(packet.header.id);
    std::cout << "Received (" << packet.header.id << ")[" << PacketCommand_Name(packetType) << "] { " << packet.header.length << " bytes } packet from client :\n";

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
        case C2S_AUTO_MATCH_REG_REQ:
        {
            if (automaticallySelectRegion)
                break;

            SC2S_AUTO_MATCH_REG_REQ autoMatchRequest;
            autoMatchRequest.ParseFromArray(packet.message.data(), packet.message.size());

            autoMatchRequest.set_region(selectedRegion);

            Packet autoMatchRequestPacket;
            autoMatchRequestPacket.header.id = C2S_AUTO_MATCH_REG_REQ;
            autoMatchRequestPacket << autoMatchRequest.SerializeAsString();

            std::cout << "[Proxy] Sending modified Auto_Match packet: \n" << autoMatchRequest.DebugString();

            serverConnection->sendPacket(autoMatchRequestPacket);
            
            // Send modified packet and return
            return;
        }
        case C2S_WHISPER_CHAT_REQ:
        {
            SC2S_WHISPER_CHAT_REQ whisperRequest;
            whisperRequest.ParseFromArray(packet.message.data(), packet.message.size());

            if (whisperRequest.targetnickname() == "Dark-Proxy")
            {
                SS2C_WHISPER_CHAT_NOT chatNotification;
                chatNotification.mutable_chatdata()->mutable_nickname()->set_originalnickname("Dark-Proxy");
                chatNotification.mutable_chatdata()->mutable_nickname()->set_streamingmodenickname("Dark-Proxy");
    
                SCHATDATA_PIECE piece;

                std::string enteredMessage = whisperRequest.mutable_chatdata()->mutable_chatdatapiecearray()->Get(0).chatstr();
                if (enteredMessage == "/help")
                {
                    sendTextMessageToClient("- Available commands -");

                    std::string commands[3];
                    commands[0] = "/help - displays available commands";
                    commands[1] = "/server - displays the currently selected server for matchmaking";
                    commands[2] = "/server [region] - selects the region as server for matchmaking. Possible values : usw, use, eu, kr, sg, au, br, jp";
                    
                    for (const std::string& command : commands)
                    {
                        sendTextMessageToClient(command);
                    }
                }
                else if (enteredMessage == "/server")
                {
                    std::string server;
                    switch (selectedRegion)
                    {
                        case 1:
                            server = "US West";
                            break;
                        case 2:
                            server = "US East";
                            break;
                        case 3:
                            server = "EU Central";
                            break;
                        case 4:
                            server = "Korea";
                            break;
                        case 5:
                            server = "Singapore";
                            break;
                        case 6:
                            server = "Sydney";
                            break;
                        case 7:
                            server = "Sao Paulo";
                            break;
                        case 8:
                            server = "Tokyo";
                            break;
                        default:
                            server = "None";
                    }
                    sendTextMessageToClient("Current server: " + server);
                }
                else if (enteredMessage.rfind("/server ", 0) == 0)
                {
                    std::string region = enteredMessage.erase(0, enteredMessage.find(" ") + 1);
                    automaticallySelectRegion = false;
                    if (region == "usw")
                    {
                        selectedRegion = 1;
                        sendTextMessageToClient("Set matchmaking region to US West!");
                    }
                    else if (region == "use")
                    {
                        selectedRegion = 2;
                        sendTextMessageToClient("Set matchmaking region to US East!");
                    }
                    else if (region == "eu")
                    {
                        selectedRegion = 3;
                        sendTextMessageToClient("Set matchmaking region to Europe!");
                    }
                    else if (region == "kr")
                    {
                        selectedRegion = 4;
                        sendTextMessageToClient("Set matchmaking region to Korea!");
                    }
                    else if (region == "sg")
                    {
                        selectedRegion = 5;
                        sendTextMessageToClient("Set matchmaking region to Singapore!");
                    }
                    else if (region == "au")
                    {
                        selectedRegion = 6;
                        sendTextMessageToClient("Set matchmaking region to Australia!");
                    }
                    else if (region == "br")
                    {
                        selectedRegion = 7;
                        sendTextMessageToClient("Set matchmaking region to Brazil!");
                    }
                    else if (region == "jp")
                    {
                        selectedRegion = 8;
                        sendTextMessageToClient("Set matchmaking region to Japan!");
                    }
                    else
                    {
                        automaticallySelectRegion = true;
                        sendTextMessageToClient("Unknown region! Possible values : usw, use, eu, kr, sg, au, br, jp");
                    }
                }
                else
                {
                    sendTextMessageToClient("Unknown command, enter /help for help.");
                }

                // Do not send packet to server
                return;
            }
        }
    }

    serverConnection->sendPacket(packet);
}

void ProxyConnection::onServerPacket(const Packet& packet)
{
    PacketCommand packetType = PacketCommand(packet.header.id);
    std::cout << "Received (" << packet.header.id << ")[" << PacketCommand_Name(packetType) << "] { " << packet.header.length << " bytes } packet from server :\n";

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
        {
            if (sentWelcomeMessage)
                break;
            sentWelcomeMessage = true;

            sendTextMessageToClient("Connected to Dark Proxy!");

            break;
        }
        case S2C_PING_REGION_SELECT_NOT:
        {
            SS2C_PING_REGION_SELECT_NOT regionSelectNotification;
            regionSelectNotification.ParseFromArray(packet.message.data(), packet.message.size());

            if (regionSelectNotification.result() == 1 && automaticallySelectRegion)
                selectedRegion = regionSelectNotification.region();
    
            break;
        }
    }

    clientConnection->sendPacket(packet);
}

void ProxyConnection::sendTextMessageToClient(const std::string& message)
{
    SS2C_WHISPER_CHAT_NOT chatNotification;
    chatNotification.mutable_chatdata()->mutable_nickname()->set_originalnickname("Dark-Proxy");
    chatNotification.mutable_chatdata()->mutable_nickname()->set_streamingmodenickname("Dark-Proxy");

    SCHATDATA_PIECE piece;
    piece.set_chatstr(message);
    chatNotification.mutable_chatdata()->mutable_chatdatapiecearray()->Add(std::move(piece));

    Packet chatNotificationPacket;
    chatNotificationPacket.header.id = S2C_WHISPER_CHAT_NOT;
    chatNotificationPacket << chatNotification.SerializeAsString();
    clientConnection->sendPacket(chatNotificationPacket);
}