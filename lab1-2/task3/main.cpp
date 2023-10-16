#include <iostream>
#include <limits>

using namespace std;

long double GetArea(int a, int b){
    return a*b;
}

int main(int argc, char* argv[]) {
    if(argc == 1) {
        cerr << "No arguments! Enter A and B values!" << endl;
        exit(1);
    }
    else if(argc == 2){
        cerr << "Not enough arguments" << endl;
        exit(1);
    }
    else {

        try {
            long double a = stod(argv[1]);
            long double b = stod(argv[2]);
            cout << "Area: " << GetArea(a, b) << endl;
        } catch (const std::invalid_argument& e) {
            std::cout << "Argument is not a number!" << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "Too big number!" << std::endl;
        }

        return 0;
    }
}
