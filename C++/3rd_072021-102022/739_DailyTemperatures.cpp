//
// Created by BrandonZu on 10/20/21.
//

#include "common.h"

// Runtime 355ms(>5.74%) | Memory Usage 89MB(>38%)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> decrease;
        vector<int> result(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++) {
            while(!decrease.empty() && temperatures[decrease.top()] < temperatures[i]) {
                result[decrease.top()] = i - decrease.top();
                decrease.pop();
            }
            decrease.push(i);
        }
        return result;
    }
};
