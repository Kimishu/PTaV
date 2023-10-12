//
// Created by Kimihito on 05.10.2023.
//

#include "SimpleFileDownloader.h"

SimpleFileDownloader::SimpleFileDownloader() {

}

SimpleFileDownloader::SimpleFileDownloader(string &filePath, string &fileURL) {
    this->filePath = filePath;
    this->fileURL = fileURL;
}

SimpleFileDownloader::~SimpleFileDownloader() {

}

size_t SimpleFileDownloader::WriteData(void *ptr, size_t size, size_t nmemb, ofstream &stream) {
    stream.write(static_cast<const char*>(ptr), size * nmemb);
    return size * nmemb;
}

bool SimpleFileDownloader::Download() {

    CURL *curl = curl_easy_init();
    ofstream out(this->filePath, ios::binary);
    CURLcode res;

    if (curl){
        curl_easy_setopt(curl, CURLOPT_URL, fileURL.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, SimpleFileDownloader::WriteData);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
        curl_easy_setopt(curl, CURLOPT_SSLCERTTYPE, "PEM");
        curl_easy_setopt(curl, CURLOPT_CAINFO, R"(..\data\sslCertificate\cacert.pem)");

        res = curl_easy_perform(curl);

        if(res == CURLE_SSL_CACERT_BADFILE || res == CURLE_PEER_FAILED_VERIFICATION) {
            cerr << curl_easy_strerror(res) << endl;

            if(!fs::exists(R"(..\data\sslCertificate)")){
                cerr << "SSL directory doesn't exist!" << endl;
            } else if(!fs::exists(R"(..\data\sslCertificate\cacert.pem)")){
                cerr << "SSL Certificate doesn't exist!" << endl;
            } else {
                cerr << "SSL Certificate is not valid?" << endl;
            }
        }
        curl_easy_cleanup(curl);
    }

    return res == CURLE_OK;
}

bool SimpleFileDownloader::Download(string &filePath, string &fileURL) {
    this->filePath = filePath;
    this->fileURL = fileURL;

    return Download();
}
