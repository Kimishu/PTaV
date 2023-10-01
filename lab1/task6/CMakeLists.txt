cmake_minimum_required(VERSION 3.24)
project(task6)

set(CMAKE_CXX_STANDARD 17)

include_directories(D:/Libs/Curl/curl-8.3.0_2-win64-mingw/include/curl)
link_directories(D:/Libs/Curl/curl-8.3.0_2-win64-mingw/bin)

add_executable(task6 main.cpp)

target_link_libraries(task6 "D:/Libs/Curl/curl-8.3.0_2-win64-mingw/lib/libcurl.dll.a")
