cmake_minimum_required(VERSION 3.8)
project(dark_proxy CXX)

add_subdirectory(protos)
add_subdirectory(dark_networking)

add_executable(dark_proxy source.cpp)

target_link_libraries(dark_proxy PRIVATE dark_networking)

#target_compile_options(dark_proxy PRIVATE -Wall -Wextra -Wpedantic)