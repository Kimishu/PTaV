cmake_minimum_required(VERSION 3.24)
project(task6)

set(CMAKE_CXX_STANDARD 17)

find_package(CURL REQUIRED)

add_executable(task6 main.cpp)

target_link_libraries(task6 CURL::libcurl)
