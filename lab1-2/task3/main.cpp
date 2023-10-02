#include <iostream>

using namespace std;

long double GetArea(int a, int b){
    return a*b;
}

int main() {
    cout << "Enter A and B sides values: ";
    long double a,b;
    cin >> a >> b;

    cout << "Area: " << GetArea(a,b) << endl;
    return 0;
}
