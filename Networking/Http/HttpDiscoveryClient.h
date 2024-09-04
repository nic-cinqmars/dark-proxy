#pragma once
#include <memory>
#include <asio.hpp>
#include <thread>

class HttpDiscoveryClient
{
public:
    struct DarkServerInfo
    {
        std::string ip;
        std::string port;
    };

    HttpDiscoveryClient(asio::io_context& context) : context(context), socket(context)
    {
    }

    const DarkServerInfo getServerRequest()
    {
        asio::ip::tcp::resolver resolver(context);
        auto endpoints = resolver.resolve("live-service.darkanddarker.com", "30000");
        asio::connect(socket, endpoints);

        message = getServerRequestMessage();
        std::cout << "Sending message : " << message << "\n";

        asio::write(socket, asio::buffer(message));
        asio::read_until(socket, asio::dynamic_buffer(receivedMessage), "}"); 

        std::cout << "Recieved message : " << receivedMessage << "\n";

        std::string ipKey = "\"ipAddress\": \"";
        std::string ip = receivedMessage.substr(receivedMessage.find(ipKey) + ipKey.length());
        ip = ip.substr(0, ip.find("\""));

        std::string portKey = "\"port\": ";
        std::string port = receivedMessage.substr(receivedMessage.find(portKey) + portKey.length());
        port = port.substr(0, port.find(","));
        
        DarkServerInfo serverInfo;
        serverInfo.ip = ip;
        serverInfo.port = port;
        return serverInfo;
    }
private:
    asio::io_context& context;
    asio::ip::tcp::socket socket;
    std::string message;
    std::string receivedMessage;

    const std::string getServerRequestMessage() const
    {
        std::stringstream messageSS;
        messageSS << "GET /dc/helloWorld HTTP/1.1\r\n";
        messageSS << "Host: live-service.darkanddarker.com:30000\r\n";
        messageSS << "Accept: */*\r\n";
        messageSS << "Accept-Encoding: deflate, gzip\r\n";
        messageSS << "Content-Type: application/json\r\n";
        messageSS << "charset: utf8\r\n";
        messageSS << "User-Agent: DungeonCrawler/UE5-CL-0 (http-legacy) Windows/10.0.19045.1.768.64bit\r\n";
        messageSS << "Content-Length: 0\r\n";
        messageSS << "\r\n";
        return messageSS.str();
    }
};