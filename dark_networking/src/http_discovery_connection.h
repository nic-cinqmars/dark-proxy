#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <asio.hpp>
#include <sstream>

class HttpDiscoveryConnection : public std::enable_shared_from_this<HttpDiscoveryConnection>
{
public:
    static std::shared_ptr<HttpDiscoveryConnection> create(asio::ip::tcp::socket socket, const std::string& darkServerIp, const uint16_t& darkServerPort)
    {
        return std::shared_ptr<HttpDiscoveryConnection>(new HttpDiscoveryConnection(std::move(socket), darkServerIp, darkServerPort));
    }

    void start()
    {
        message = getServerMessage();

        auto self(shared_from_this());

        asio::async_read_until(socket, asio::dynamic_buffer(receivedMessage), "\r\n\r\n",
            [this, self](const std::error_code& ec, size_t)
            {
                if (!ec)
                {
                    asio::async_write(socket, asio::buffer(message, message.length()),
                        [this, self](const std::error_code&, const size_t&)
                        {
                            
                        }
                    );
                }
            }
        );
    }

private:
    asio::ip::tcp::socket socket;
    std::string message;
    std::string receivedMessage;
    const std::string darkServerIp;
    const uint16_t darkServerPort;

    HttpDiscoveryConnection(asio::ip::tcp::socket socket, const std::string& darkServerIp, const uint16_t& darkServerPort): socket(std::move(socket)), darkServerIp(darkServerIp), darkServerPort(darkServerPort)
    {

    }

    const std::string currentDateTime() const
    {
        std::time_t now = time(0);
        char buff[50];
        strftime(buff, sizeof(buff), "%a, %d %b %Y %T %Z", gmtime(&now));
        return buff;
    }

    const std::string getServerMessage() const
    {
        std::stringstream messageBodySS;
        messageBodySS << "{\n  \"ipAddress\": \"" << darkServerIp << "\",\n  \"port\": " << darkServerPort << ",\n  \"remote\": \"" << socket.remote_endpoint().address() << "\"\n}";
        std::stringstream messageSS;
        messageSS << "HTTP/1.1 200 OK\r\n";
        messageSS << "content-type: text/plain; charset=utf-8\r\n";
        messageSS << "content-length: " << messageBodySS.str().length() << "\r\n";
        messageSS << "server: Armeria/unknown\r\n";
        messageSS << "date: " << currentDateTime() << "\r\n";
        messageSS << "\r\n";
        messageSS << messageBodySS.str();
        return messageSS.str();
    }
};