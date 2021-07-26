//
// Created by BrandonZu on 2021/7/26.
//

#include "common.h"

class Solution {
    int flag = 0;
    int result = -1;
    vector<int> path;
public:
    void dfs(vector<int>& digits, int pos, int n) {
        // Found Answer
        if(flag == 2)
            return;
        // Leaf Node
        if(pos == digits.size() - 1) {
            int tmp = 0;
            for(int x : path) {
                tmp *= 10;
                tmp += x;
            }
            if(tmp == n)
                flag = 1;

            return;
        }
        path.push_back(digits[])
    }

    int nextGreaterElement(int n) {
        vector<int> digits;
        int tmp = n;
        while(tmp) {
            digits.push_back(tmp % 10);
            tmp /= 10;
        }

        dfs(digits, 0, n);

        return result;
    }
};
