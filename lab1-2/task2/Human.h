//
// Created by Grimlock on 02.10.2023.
//

#ifndef TASK2_HUMAN_H
#define TASK2_HUMAN_H

#include <iostream>

using namespace std;

class Human{
public:
    string surname;
    string name;
    unsigned short age;
    Human(){}
    Human(string surname, string name, unsigned short age){
        this->surname = std::move(surname);
        this->name = std::move(name);
        this->age = age;
    }
};

#endif //TASK2_HUMAN_H
