//
// Created by Grimlock on 02.10.2023.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#include "task1.h"

using namespace std;

int main(){
    srand(time(NULL));

    vector<pair<int, int>> numbers = {};
    for(int i = 0; i < 10000; i++){
        int num = GetRandomNumber();
        auto iter = find_if(numbers.begin(), numbers.end(), [num](pair<int, int>& pr){
            if(num == pr.first)
                return true;
            return false;
        });
        if(iter != numbers.end() && (iter->first == num)){
            iter->second +=1;
        } else {
            numbers.push_back(pair<int, int>(num,1));
        }
    }

    for(const pair<int,int>& pr : numbers){
        assert(pr.first >= 5 && pr.first <= 50);
    }
   cout << "Test successfully passed!" << endl;
    return 0;
}