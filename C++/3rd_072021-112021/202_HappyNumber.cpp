//
// Created by BrandonZu on 2021/7/23.
//

#include "common.h"

// Runtime 4ms(>45%) | Memory Usage 6.3ms(>43%)
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> cycle;
        while(n != 1) {
            int sum = 0;
            while(n) {
                sum += pow(n % 10, 2);
                n /= 10;
            }
            if(cycle.find(sum) != cycle.end())
                return false;

            cycle.insert(sum);
            n = sum;
        }
        return true;
    }
};
