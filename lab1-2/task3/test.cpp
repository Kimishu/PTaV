#include <iostream>
#include <cassert>

using namespace std;

long double GetArea(int a, int b){
    return a*b;
}

int main(){

    long double a = 2.0;
    long double b = 4.0;

    assert(GetArea(a,b) == 8);
    cout << "TestGetArea passed!" << endl;
    return 0;
}