#include "RectangleChecker/RectangleChecker.h"
#include <iostream>

using namespace std;

int main() {
    ///Rectangle
    cout << RectangleChecker({5,3,5,3},{90,90,90,90}).GetType() << endl;

    ///Square
    cout << RectangleChecker({5,5,5,5},{90,90,90,90}).GetType() << endl;

    ///Parallelogram
    cout << RectangleChecker({4,3,4,3},{120,60,120,60}).GetType() << endl;

    ///Rhombus
    cout << RectangleChecker({3,3,3,3},{120,60,120,60}).GetType() << endl;

    ///Kite
    cout << RectangleChecker({1,1,2,2},{120,90,120,30}).GetType() << endl;

    ///Trapezoid
    cout << RectangleChecker({1,2,3,4},{120,60,120,60}).GetType() << endl;

    ///Quadrilateral
    cout << RectangleChecker({1,2,3,4},{115,60,125,60}).GetType() << endl;

    return EXIT_SUCCESS;
}
