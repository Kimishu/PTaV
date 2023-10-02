#include <stdio.h>
#include <curl/curl.h>
#include <iostream>
#include <algorithm>

using namespace std;

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main(int argc, char* argv[]) {
    if(argc == 3){
        string url = string(argv[1]);
        string outputFilePath = string(argv[2]);

        string urlFileExtension = url.substr(url.size() - 4);
        if(urlFileExtension.find('.') == string::npos){
            cout << "Wrong url!" << endl;
            exit(EXIT_FAILURE);
        }
        if(urlFileExtension != outputFilePath.substr(outputFilePath.size() - 4)){
            cout << "Different file extensions!" << endl;
            exit(EXIT_FAILURE);
        }

        CURL *curl;
        FILE *fp;
        CURLcode res;

        curl = curl_easy_init();
        if (curl) {
            fp = fopen(outputFilePath.c_str(),"wb");
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
            fclose(fp);
        }
    }else {
        cout << "Wrong parameters count!" << endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}

//string url = "https://www.bsuir.by/m/12_100229_1_122976.pdf";
//string outputFilePath = "..\\test.pdf";