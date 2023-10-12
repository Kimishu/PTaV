cmake_minimum_required(VERSION 3.24)
project(task6)

set(CMAKE_CXX_STANDARD 17)

find_package(CURL REQUIRED)

add_executable(task6 src/main.cpp src/SimpleFileDownloader/SimpleFileDownloader.h src/SimpleFileDownloader/SimpleFileDownloader.cpp)
add_executable(task6Test src/test.cpp src/SimpleFileDownloader/SimpleFileDownloader.h src/SimpleFileDownloader/SimpleFileDownloader.cpp)

target_link_libraries(task6 CURL::libcurl)
target_link_libraries(task6Test CURL::libcurl)
