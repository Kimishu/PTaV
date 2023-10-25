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
    if(AnglesEqual()) {
        if(SidesEqual())
            return "Square";
        else if(OppositeSidesEqual())
            return "Rectangle";
    }
    
    return "Quadrilateral";
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

bool RectangleChecker::SidesEqual() {
    return std::adjacent_find(sides.begin(), sides.end(), std::not_equal_to<>()) == sides.end();
}

bool RectangleChecker::OppositeSidesEqual() {
    return std::adjacent_find(sides.begin(), sides.end(), std::equal_to<>()) == sides.end();
}

bool RectangleChecker::AnglesEqual() {
    return std::adjacent_find(angles.begin(), angles.end(), std::not_equal_to<>()) == angles.end();
}

