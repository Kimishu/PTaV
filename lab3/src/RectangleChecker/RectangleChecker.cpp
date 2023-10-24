//
// Created by Grimlock on 24.10.2023.
//

#include <numeric>
#include <iostream>
#include "RectangleChecker.h"

RectangleChecker::RectangleChecker() {

}

RectangleChecker::RectangleChecker(std::array<long double, 4> sides, std::array<long double, 4> angles) {
    this->sides = sides;
    this->angles = angles;
    if(!CheckSides()) {
        std::cerr << "Wrong side(s) value!" << std::endl;
        std::exit(1);
    }
    if(!CheckAngles()) {
        std::cerr << "Wrong angle(s) value!" << std::endl;
        std::exit(1);
    }
}

RectangleChecker::~RectangleChecker() {

}

std::string RectangleChecker::GetType() {
    if(IsRectangle()) {
        if(IsSquare())
            return "Square";
        return "Rectangle";
    }
    if(IsParallelogram()){
        if(IsRhombus())
            return "Rhombus";
        return "Parallelogram";
    }
    if(IsDeltoid())
        return "Deltoid";
    if(IsTrapezoid())
        return "Trapezoid";
    return "None";
}

bool RectangleChecker::CheckSides() {
    return *std::min(sides.begin(), sides.end()) > 0;
}

bool RectangleChecker::CheckAngles() {
    long double result = std::accumulate(angles.begin(), angles.end(), 0);;
    bool valid = std::find_if(angles.begin(), angles.end(), [](long double& value){
        if(value >= 360 || value <= 0)
            return false;
        return true;
    });

    return (result == 360) && valid;
}
