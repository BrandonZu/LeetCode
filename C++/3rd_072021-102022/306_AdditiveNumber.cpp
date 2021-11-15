//
// Created by BrandonZu on 11/15/21.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 5.8MB(>98%)
class Solution {
public:
    string bigAdd(string a, string b) {
        int carry = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string res;
        for(int i = 0; i < max(a.size(), b.size()) || carry; i++) {
            int tmp = 0;
            if(i < a.size())
                tmp += a[i] - '0';
            if(i < b.size())
                tmp += b[i] - '0';
            tmp += carry;
            res.push_back('0' + tmp % 10);
            carry = tmp / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool isAdditiveNumber(string num) {
        if(num.size() < 3) return false;
        for(int i = 0; i < num.size() / 2; i++) {
            for(int j = i + 1; j < num.size() * 2 / 3; j++) {
                // Number 1 [a+1, b] | Number 2 [b+1, c]
                int a = -1, b = i, c = j;
                while(true) {
                    if(b - a > 1 && num[a + 1] == '0' || c - b > 1 && num[b + 1] == '0')
                        break;
                    string num1 = num.substr(a + 1, b - a), num2 = num.substr(b + 1, c - b);
                    string sum = bigAdd(num1, num2);
                    if(num.substr(c + 1, sum.size()) != sum)
                        break;
                    a = b, b = c, c = c + sum.size();
                    if(c == num.size() - 1)
                        return true;
                }
            }
        }
        return false;
    }
};
