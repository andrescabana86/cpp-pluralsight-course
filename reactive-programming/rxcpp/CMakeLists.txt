cmake_minimum_required(VERSION 3.2.2)
project(rx_cpp)
set(CMAKE_CXX_STANDARD 20)

find_package(rxcpp CONFIG REQUIRED)

add_executable(rx_cpp main.cpp)

target_link_libraries(rx_cpp PRIVATE rxcpp)
