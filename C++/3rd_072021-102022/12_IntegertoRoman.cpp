//
// Created by BrandonZu on 2021/8/15.
//

#include "common.h"

// Runtime 7ms(>57%) | Memory Usage 5.9MB(>92%)
class Solution {
public:
    string intToRoman(int num) {
        char transMap[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        string res, cur;
        int digit, cnt = -1;
        while(num) {
            digit = num % 10;
            num /= 10;
            cnt++;
            cur.clear();
            if(digit == 0) {
                continue;
            }
            else if(digit >= 1 && digit <= 3) {
                for(int i = 0; i < digit; i++)
                    cur.push_back(transMap[cnt * 2]);
            }
            else if(digit >= 4 && digit <= 5) {
                for(int i = 0; i < 5 - digit; i++)
                    cur.push_back(transMap[cnt * 2]);
                cur.push_back(transMap[cnt * 2 + 1]);
            }
            else if(digit >= 6 && digit <= 8) {
                cur.push_back(transMap[cnt * 2 + 1]);
                for(int i = 0; i < digit - 5; i++)
                    cur.push_back(transMap[cnt * 2]);
            }
            else if(digit == 9) {
                cur.push_back(transMap[cnt * 2]);
                cur.push_back(transMap[cnt * 2 + 2]);
            }
            reverse(cur.begin(), cur.end());
            res.append(cur);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
