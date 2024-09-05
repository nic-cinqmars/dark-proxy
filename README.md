
# dark-proxy

A C++ man in the middle proxy made for the game Dark and Darker.


## Run Locally

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


## Connect to Proxy
On whatever platform you are playing, add the following launch option

```bash
  server=127.0.0.1:30000
```

Launch the game as normal and you should now be connected to Dark and Darker through this proxy!