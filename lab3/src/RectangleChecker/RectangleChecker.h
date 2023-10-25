//
// Created by Grimlock on 24.10.2023.
//

#ifndef LAB3_RECTANGLECHECKER_H
#define LAB3_RECTANGLECHECKER_H

#include <array>
#include <string>
#include <algorithm>

class RectangleChecker {
    std::array<long double, 4> sides{};
    std::array<long double, 4> angles{};

    bool SidesEqual();
    bool OppositeSidesEqual();
    bool AnglesEqual();

    bool CheckSides();
    bool CheckAngles();
public:
    RectangleChecker();
    RectangleChecker(std::array<long double, 4> sides, std::array<long double, 4> angles);
    ~RectangleChecker();

    std::string GetType();
};


#endif //LAB3_RECTANGLECHECKER_H
