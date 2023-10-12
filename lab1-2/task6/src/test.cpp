//
// Created by Kimihito on 05.10.2023.
//

#include "SimpleFileDownloader/SimpleFileDownloader.h"
#include <cassert>

int main(){

    string url = "https://www.w3.org/WAI/ER/tests/xhtml/testfiles/resources/pdf/dummy.pdf";
    string outputFilePath = "..\\data\\dummy.pdf";

    SimpleFileDownloader downloader(outputFilePath,url);

    //Checking for successful download
    assert(downloader.Download() == true);

    //Checking for file existence
    assert(fs::exists(outputFilePath) == true);

    cout << "Test for task 6 passed" << endl;

    return 0;
}