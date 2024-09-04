#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include <memory>

struct PacketHeader
{
    uint16_t length = 0;
    const uint16_t paddingBytes = 0;
    uint16_t id;
    const uint16_t paddingBytes2 = 0;
};

struct Packet
{
    PacketHeader header{};
    std::vector<char> message;

    friend Packet& operator << (Packet& packet, const std::string& message)
    {
        std::copy(message.begin(), message.end(), std::back_inserter(packet.message));

        packet.header.length = sizeof(PacketHeader) + packet.message.size();

        return packet;
    }
};