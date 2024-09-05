#define ASIO_STANDALONE
#include <dark_networking/http_discovery_server.h>
#include <dark_networking/proxy.h>

int main(int argc, char* argv[])
{
    uint16_t discoveryServerPort = 30000;
	std::string proxyIp = "127.0.0.1";
	uint16_t proxyPort = 25555;

	if (argc > 1)
	{
		for (int i = 0; i < argc; i++)
		{
			std::string arg(argv[i]);
            if (arg.find("discoveryPort=") != std::string::npos)
			{
				discoveryServerPort = std::stoi(arg.substr(14));
			}
			if (arg.find("ip=") != std::string::npos)
			{
				proxyIp = arg.substr(3);
			}
			else if (arg.find("port=") != std::string::npos)
			{
				proxyIp = std::stoi(arg.substr(5));
			}
		}
	}

	HttpDiscoveryServer discoveryServer(discoveryServerPort, proxyIp, proxyPort);

    Proxy proxy(proxyPort);
    proxy.start();
    while(1)
    {
        proxy.update();
    }
    return 0;
}