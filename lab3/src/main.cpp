#include "RectangleChecker/RectangleChecker.h"
#include <array>
#include <iostream>

int main() {
    std::array<long double, 4> sides{5,3,3,3};
    std::array<long double, 4> angles{120,60,150,30};
    RectangleChecker rectangleChecker(sides, angles);

    std::cout << rectangleChecker.GetType() << std::endl;
    return 0;
}
