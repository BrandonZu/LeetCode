//
// Created by BrandonZu on 9/30/21.
//

#include "common.h"

// Runtime 8ms(>59%) | Memory Usage 6.8MB(>62%)
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        vector<int> res(len1 + len2, 0);

        for(int i = len1 - 1; i >= 0; i--) {
            for(int j = len2 - 1; j >= 0; j--) {
                int pos = i + j + 1;
                int sum = res[pos] + (num1[i] - '0') * (num2[j] - '0');
                res[pos] = sum % 10;
                res[pos - 1] += sum / 10;
            }
        }

        // Remove extra zeros
        int pos = 0;
        for(pos = 0; pos < len1 + len2; pos++) {
            if(res[pos] != 0) {
                break;
            }
        }

        string resString;
        for(int i = pos; i < len1 + len2; i++) {
            resString.push_back('0' + res[i]);
        }
        if(resString.empty())
            return "0";
        else
            return resString;
    }
};

