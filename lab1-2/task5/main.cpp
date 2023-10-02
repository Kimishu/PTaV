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

int main(int argc, char*argv[]) {
    if(argc == 3){
        string filePath = argv[1];
        string extension = argv[2];
        if(extension.size() != 4 || extension[0] != '.' ){
            cout << "Wrong extension format!" << endl;
            std::exit( EXIT_FAILURE );
        }
        CheckDirectories(filePath, extension);
    } else {
        cout << "Check your parameters!" << endl;
        std::exit(EXIT_FAILURE);
    }

    return 0;
}
//D:\\Programs\\7sem\\TIVP .cpp