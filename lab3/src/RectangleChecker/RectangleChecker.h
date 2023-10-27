//
// Created by Grimlock on 24.10.2023.
//

#ifndef LAB3_RECTANGLECHECKER_H
#define LAB3_RECTANGLECHECKER_H

#include <array>
#include <string>
#include <algorithm>

class RectangleChecker {
    static std::array<long double, 4> sides;
    static std::array<long double, 4> angles;

    static bool SidesEqual();
    static bool OppositeSidesEqual();
    static bool AnglesEqual();
    static bool OppositeAnglesEqual();

    static bool CheckSides();
    static bool CheckAngles();
public:
    RectangleChecker();
    RectangleChecker(std::array<long double, 4> sides, std::array<long double, 4> angles);
    ~RectangleChecker();

    static std::string GetType();
};


#endif //LAB3_RECTANGLECHECKER_H
