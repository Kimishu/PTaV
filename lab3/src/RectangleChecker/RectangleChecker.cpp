//
// Created by Grimlock on 24.10.2023.
//

#include <numeric>
#include <iostream>
#include "RectangleChecker.h"

std::array<long double, 4> RectangleChecker::sides;
std::array<long double, 4> RectangleChecker::angles;

RectangleChecker::RectangleChecker() {

}

RectangleChecker::RectangleChecker(std::array<long double, 4> sides, std::array<long double, 4> angles) {
    this->sides = sides;
    this->angles = angles;
    if(!CheckSides()) {
        throw std::invalid_argument("Wrong side(s) values!");
    }
    if(!CheckAngles()) {
        throw std::invalid_argument("Wrong angle(s) values!");
    }
}

RectangleChecker::~RectangleChecker() {

}

std::string RectangleChecker::GetType() {
    if(AnglesEqual()) {
        if(SidesEqual())
            return "Square";
        else if(OppositeSidesEqual())
            return "Rectangle";
    }
    if(OppositeAnglesEqual()){
        if(SidesEqual())
            return "Rhombus";
        else if(OppositeSidesEqual())
            return "Parallelogram";
    }

    if(((angles[0] + angles[1]) == 180 && (angles[2] + angles[3]) == 180) &&
        (angles[0] + angles[2] != 180 && angles[1] + angles[3] != 180))
        return "Trapezoid";

    if(((sides[0] == sides[1] && sides[2] == sides[3]) ||
       (sides[0] == sides[3] && sides[1] == sides[2])) &&
       ((angles[0] == angles[2]) ||
       (angles[1] == angles[3])))
        return "Kite";

    return "Quadrilateral";
}

bool RectangleChecker::CheckSides() {
    return *std::min(sides.begin(), sides.end()) >= 0;
}

bool RectangleChecker::CheckAngles() {
    long double result = std::accumulate(angles.begin(), angles.end(), 0);
    bool valid = std::find_if(angles.begin(), angles.end(), [](long double& value){
        if(value >= 360 || value <= 0)
            return false;
        return true;
    });
    return (result == 360) && valid;
}

bool RectangleChecker::SidesEqual() {
    return std::all_of(sides.begin(), sides.end(), [](const auto& side){
        return side == sides[0];
    });
}

bool RectangleChecker::OppositeSidesEqual() {
    return sides[0] == sides[2] && sides[1] == sides[3];
}

bool RectangleChecker::AnglesEqual() {
    return std::all_of(angles.begin(), angles.end(),[](const auto& angle){
        return angle == angles[0];
    });
}

bool RectangleChecker::OppositeAnglesEqual() {
    return std::adjacent_find(angles.begin(), angles.end(), std::equal_to<>()) == angles.end();;
}

