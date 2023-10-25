#include "RectangleChecker/RectangleChecker.h"
#include <array>
#include <iostream>

int main() {
    std::array<long double, 4> sides{5,5,5,5};
    std::array<long double, 4> angles{90,90,90,90};
    RectangleChecker rectangleChecker(sides, angles);


    std::cout << rectangleChecker.GetType() << std::endl;
    return EXIT_SUCCESS;
}
