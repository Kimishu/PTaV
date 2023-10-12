//
// Created by Kimihito on 05.10.2023.
//

#ifndef TASK6_SIMPLEFILEDOWNLOADER_H
#define TASK6_SIMPLEFILEDOWNLOADER_H

#include <iostream>
#include <curl/curl.h>
#include <algorithm>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

class SimpleFileDownloader {
    string filePath;
    string fileURL;

    static size_t WriteData(void *ptr, size_t size, size_t nmemb, ofstream &stream);
public:
    SimpleFileDownloader();
    SimpleFileDownloader(string& filePath, string& fileURL);
    ~SimpleFileDownloader();
    bool Download();
    bool Download(string& filePath, string& fileURL);
};


#endif //TASK6_SIMPLEFILEDOWNLOADER_H
