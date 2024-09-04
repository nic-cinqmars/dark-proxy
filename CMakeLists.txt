cmake_minimum_required(VERSION 3.8)
project(dark-networking CXX)

add_subdirectory(Protos)

add_executable(dark-proxy Source.cpp)
target_link_libraries(dark-proxy PUBLIC "$<LINK_LIBRARY:WHOLE_ARCHIVE,protos>")

#target_compile_options(dark-proxy PRIVATE -Wall -Wextra -Wpedantic)