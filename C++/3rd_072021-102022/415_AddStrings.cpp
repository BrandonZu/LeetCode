//
// Created by BrandonZu on 11/5/21.
//

#include "common.h"

// Runtime 4ms(>80%) | Memory Usage 6.8MB(>70%)
class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num2.size() > num1.size())
            return addStrings(num2, num1);

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry = 0;
        int i = 0, j = 0;
        int pos = 0;
        string result;

        while(i < num1.size() && j < num2.size()) {
            int cur = num1[i] - '0' + num2[i] - '0' + carry;
            carry = cur / 10;
            cur = cur % 10;
            result.push_back(cur + '0');
            i++, j++;
        }

        while(i < num1.size()) {
            int cur = num1[i] - '0' + carry;
            carry = cur / 10;
            cur = cur % 10;
            result.push_back(cur + '0');
            i++;
        }
        if(carry)
            result.push_back('0' + carry);

        reverse(result.begin(), result.end());

        return result;
    }
};

