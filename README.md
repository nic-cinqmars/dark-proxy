
# dark-proxy

A C++ man in the middle proxy made for the game Dark and Darker.

*This has only been tested on linux and might not work on other platforms.*


## Requirements
- [protobuf](https://github.com/protocolbuffers/protobuf/tree/main)
- [asio](https://think-async.com/Asio/)


## Compile and run

Clone the project and submodules

```bash
  git clone git@github.com:nic-cinqmars/dark-proxy.git --recurse-submodules
```

Go to the project directory

```bash
  cd dark-proxy
```

Compile using CMake and Make

```bash
  mkdir build
  cd build
  cmake ..
  make -j 8
```

Start the proxy

```bash
  ./dark-proxy
```


## Customization

The following arguments can be passed to customize some parts of the program:

- ```ip=``` (changes the ip the discovery server redirects to, default is 127.0.0.1)
- ```port=``` (changes the port the proxy runs on, default is 25555)
- ```discoveryPort=``` (changes the port the discovery server runs on, default is 30000)

For example, running the proxy on a distant server with ip 123.123.123.123, you could run the proxy using this command:

```
./dark-proxy ip=123.123.123.123
```
## Connect to the proxy
On whatever platform you are playing, add the following launch option:

```bash
  server=127.0.0.1:30000
```

*(change the ip and port to that of the discovery server)*

Launch the game and you should now be connected to Dark and Darker through this proxy!