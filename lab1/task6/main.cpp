#include <iostream>
#include <string>
#include <fstream>
#include <curl.h>

using namespace std;

size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

bool downloadContent(const std::string& url, std::string& content) {
    CURL* curl = curl_easy_init();
    if(!curl) {
        return false;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &content);
    CURLcode res = curl_easy_perform(curl);
    if(res != CURLE_OK) {
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        curl_easy_cleanup(curl);
        return false;
    }

    curl_easy_cleanup(curl);
    return true;
}

int main(int argc, char* argv[]) {


    std::string url = "https://www.w3.org/WAI/ER/tests/xhtml/testfiles/resources/pdf/dummy.pdf";
    std::string content;
    std::string output = "D:\\Programs\\7sem\\TIVP";
    downloadContent(url, content);

    std::ofstream out(output);

    out << content;
    out.close();

    std::cout << "Downloaded content saved to " << output << std::endl;
    return 0;
}