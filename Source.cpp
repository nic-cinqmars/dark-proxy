#define ASIO_STANDALONE
#include "Networking/Http/HttpDiscoveryServer.h"
#include "Networking/Proxy/Proxy.h"

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