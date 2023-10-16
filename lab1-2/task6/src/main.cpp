#include "SimpleFileDownloader/SimpleFileDownloader.h"

using namespace std;

int main() {
    string url = "https://www.w3.org/WAI/ER/tests/xhtml/testfiles/resources/pdf/dummy.pdf";
    string outputFilePath = "..\\data\\dummy.pdf";

    SimpleFileDownloader downloader(outputFilePath,url);
    downloader.Download();

    return 0;
}

//string url = "https://www.bsuir.by/m/12_100229_1_122976.pdf";
//string outputFilePath = "..\\test.pdf";