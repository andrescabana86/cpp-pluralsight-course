cmake_minimum_required(VERSION 3.2.2)
project(ch_weather_statistics)

set(CMAKE_CXX_STANDARD 17)

add_executable(ch_weather_statistics main.cpp WeatherStatistics.hpp WeatherStatistics.cpp)