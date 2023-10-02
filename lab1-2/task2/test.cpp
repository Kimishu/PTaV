//
// Created by Grimlock on 02.10.2023.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <numeric>
#include "Human.h"

using namespace std;

int main(){

    vector<Human> people = {
            Human("Hoho", "Shino", 15),
            Human("Hojo", "Mina", 25),
            Human("Ryomen", "Sukuna", 2000),
            Human("Yuji", "Itadori", 18),
            Human("Fushiguro", "Megumi", 18),
            Human("Nobara", "Kugisaki", 18),
            Human("Gojo", "Satoru", 28),
            Human("Nanami", "Kento" ,28),
            Human("Shojo", "Ieri", 27),
            Human("Toji", "Fushiguro", 40)
    };

    cout << "\tTesting Max: ";
    assert(std::max_element(people.begin(), people.end(),
                     [](const Human& h1, const Human& h2) {
                         return h1.age < h2.age;
                     })->age == 2000);
    cout << "passed!" << endl;

    cout << "\tTesting Min: ";
    assert(std::max_element(people.begin(), people.end(),
                            [](const Human& h1, const Human& h2) {
                                return h1.age > h2.age;
                            })->age == 15);
    cout << "passed!" << endl;

    cout << "\tTesting Avg: ";
    assert(accumulate(people.begin(), people.end(),0,[](int sum, const Human& human){
        return sum + human.age;
    })/people.size() == 221);
    cout << "passed!" << endl;
}