#include <iostream>
#include <filesystem>
#include <vector>
#include <cassert>


using namespace std;
namespace fs = filesystem;

vector<string> pathes;

bool CheckDirectories(string filePath, string extension){
    pathes.clear();
    if(fs::is_directory(filePath)){
        for (const fs::directory_entry & entry : fs::directory_iterator(filePath)) {
            CheckDirectories(entry.path().string(), extension);
        }
    } else {
        if(filePath.substr(filePath.length()-4) == extension){
            pathes.push_back(filePath);
        }
    }
}

int main(){

    cout << "Test directories: ";

    string path = "D:\\Programs\\7sem\\TIVP\\";
    string extension = ".cpp";
    CheckDirectories(path, extension);
    for(const string& filePath: pathes){
        assert(filePath.find(path) != string::npos);
    }
    cout << "passed" << endl;

    return 0;
}