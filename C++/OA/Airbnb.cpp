//
// Created by BrandonZu on 10/16/21.
//

#include "common.h"

// Leetcdoe 166
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans;
        // Corner Cases
        if(numerator == 0) return "0";
        if(numerator < 0 ^ denominator < 0) ans += '-';

        long n = labs(numerator), d = labs(denominator);
        ans += to_string(n / d);
        long remain = n % d;
        if(remain == 0) return ans;
        ans += '.';

        unordered_map<int, int> remainSet;
        while(remain) {
            if(remainSet.find(remain) != remainSet.end()) {
                ans.insert(remainSet[remain], "(");
                ans += ')';
                break;
            }
            remainSet[remain] = ans.size();
            remain *= 10;
            ans += to_string(remain / d);
            remain = remain % d;
        }
        return ans;
    }
};
