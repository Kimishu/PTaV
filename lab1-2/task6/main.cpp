#include <iostream>
#include <algorithm>
#include <curl/curl.h>

using namespace std;

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main(int argc, char** argv) {

    string url = "https://www.w3.org/WAI/ER/tests/xhtml/testfiles/resources/pdf/dummy.pdf";//string(argv[1]);
    string outputFilePath = "..\\dummy.pdf";

    CURL *curl = curl_easy_init();
    FILE *fp;
    CURLcode res;

    if (curl)
    {
        fp = fopen(outputFilePath.c_str(),"wb");

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_SSLCERTTYPE, "PEM");
        curl_easy_setopt(curl, CURLOPT_CAINFO, "..\\cacert.pem");

        res = curl_easy_perform(curl);

        if(res == CURLE_OK){
            cout << "Done" << endl;
        }

        curl_easy_cleanup(curl);
        fclose(fp);
    }

    return 0;
}

//string url = "https://www.bsuir.by/m/12_100229_1_122976.pdf";
//string outputFilePath = "..\\test.pdf";