//
// Created by BrandonZu on 9/30/21.
//

#include "common.h"

// Runtime 4ms(62%）| Memory Usage 6.3MB(>62%)
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        while(i >= 0 && j >= 0) {
            int sum = carry + a[i] - '0' + b[j] - '0';
            res.push_back('0' + sum % 2);
            carry = sum / 2;
            i--, j--;
        }
        while(i >= 0) {
            if(carry == 0) {
                res.push_back(a[i]);
            }
            else {
                int sum = a[i] - '0' + carry;
                carry = sum / 2;
                res.push_back(sum % 2 + '0');
            }
            i--;
        }
        while(j >= 0) {
            if(carry == 0) {
                res.push_back(b[j]);
            }
            else {
                int sum = b[j] - '0' + carry;
                carry = sum / 2;
                res.push_back(sum % 2 + '0');
            }
            j--;
        }
        if(carry == 1) {
            res.push_back('1');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
