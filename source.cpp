#define ASIO_STANDALONE
#include <dark_networking/http_discovery_server.h>
#include <dark_networking/proxy.h>

int main()
{
    HttpDiscoveryServer httpDiscovery(30000, "192.168.2.81", 25555);

    Proxy proxy(25555);
    proxy.start();
    while(1)
    {
        proxy.update();
    }
    return 0;
}