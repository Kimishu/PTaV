#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

bool CheckDirectories(string filePath, string extension){
    if(fs::is_directory(filePath)){
        for (const fs::directory_entry & entry : fs::directory_iterator(filePath)) {
            CheckDirectories(entry.path().string(), extension);
        }
    } else {
        if(filePath.substr(filePath.length()-4) == extension){
            cout << filePath << endl;
        }
    }
}

int main() {
    cout << "Enter a file path & file extension: ";
    string filePath, extension;
    cin >> filePath >> extension;
    cout << endl;
    CheckDirectories(filePath, extension);

    return 0;
}
//D:\Programs\7sem\TIVP .cpp