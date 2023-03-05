cmake_minimum_required(VERSION 3.2.2)
project(ch_weather_statistics)

set(CMAKE_CXX_STANDARD 20)

add_executable(ch_weather_statistics main.cpp WeatherStatistic.h WeatherStatistic.cpp)

add_custom_command(
    TARGET ch_weather_statistics POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/data
    ${CMAKE_CURRENT_BINARY_DIR}/data
)