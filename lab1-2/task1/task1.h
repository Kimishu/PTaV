//
// Created by Grimlock on 02.10.2023.
//

#ifndef TASK1_TASK1_H
#define TASK1_TASK1_H
#include <iostream>

int GetRandomNumber(){
    return (rand()%46+5);
}

void Print(){
    ;
    std::cout << "Hello, World!\nAndhiagain!\n" << std::string( GetRandomNumber(), '!') << std::endl;
}

#endif //TASK1_TASK1_H
