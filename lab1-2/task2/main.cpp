#include <iostream>
#include <utility>
#include <vector>
#include <conio.h>
#include <algorithm>
#include <numeric>

#include "Human.h"

using namespace std;


int main() {

    vector<Human> people;
    while(true){
        cout << "\tMenu\n======\n1. Enter 10 people data\n2. Show info\n3. Exit\n======\n";
        string tmp;
        cin >> tmp;
        if(tmp == "1"){
            cout << "Enter people data (Surname Name Age)\n";
            int count = 0;
            while(count < 10){
                string surname, name;
                unsigned short age;
                cin >> surname >> name >> age;
                people.push_back(Human(surname, name, age));
                count++;
            }
        }
        if(tmp == "2"){
            cout << "People data: \n";
            for(Human& human : people){
                cout << human.surname << " " << human.name << " " << human.age << endl;
            }
            cout << string(10, '=') << endl;
            cout << "Maximum age: " << std::max_element(people.begin(), people.end(),
                                                                         [](const Human& h1, const Human& h2) {
                                                                             return h1.age < h2.age;
                                                                         })->age << endl;

            cout << "Minimum age: " << std::max_element(people.begin(), people.end(),
                                                    [](const Human& h1, const Human& h2) {
                                                        return h1.age > h2.age;
                                                    })->age << endl;

            cout << "Average age: " << accumulate(people.begin(), people.end(),0,[](int sum, const Human& human){
                return sum + human.age;
            })/people.size() << endl;


        }
        if(tmp == "3"){
            cout << "Bye-bye!!!" << endl;
            break;
        }

    }

    return 0;
}

/*
Hoho Shino 15
Hojo Mina 25
Ryomen Sukuna 2000
Yuji Itadori 18
Fushiguro Megumi 18
Nobara Kugisaki 18
Gojo Satoru 28
Nanami Kento 28
Shojo Ieri 27
Toji Fushiguro 40
 */