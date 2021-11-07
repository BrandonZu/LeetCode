//
// Created by BrandonZu on 2021/8/19.
//

#include "common.h"

// Runtime 4ms(>67%) | Memory Usage 7.3MB(>36%)
class Solution {
public:
    vector<string> less_than_20 = {
            "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> high = {"", "Thousand", "Million", "Billion"};

    string numberToWords(int num) {
        if(num == 0) {
            return "Zero";
        }
        string res;
        for(int i = 1e9, j = 3; j >= 0; i /= 1000, j--) {
            if(num >= i) {
                res += helper(num / i) + " " + high[j] + " ";
                num %= i;
            }
        }
        // Remove extra spaces
        while(res.back() == ' ')
            res.pop_back();
        return res;
    }

    string helper(int num) {
        string res;
        // Add the space at the end because it's easy to remove
        if(num >= 100) {
            res += less_than_20[num / 100] + " " + "Hundred" + " ";
            num %= 100;
        }
        if(num >= 20) {
            res += tens[num / 10] + " ";
            num %= 10;
        }
        if(num > 0) {
            res += less_than_20[num] + " ";
        }
        // Remove extra spaces
        while(res.back() == ' ')
            res.pop_back();
        return res;
    }
};
