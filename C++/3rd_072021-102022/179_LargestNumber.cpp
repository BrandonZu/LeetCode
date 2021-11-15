//
// Created by BrandonZu on 11/14/21.
//

#include "common.h"

// Runtime 4ms(>96%) | Memory Usage 11.5MB(>23%)
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(int num: nums)
            str.push_back(to_string(num));
        sort(str.begin(), str.end(), [&] (string& a, string& b) { return a + b > b + a; });
        string res;
        for(auto p = str.begin(); p != str.end(); p++)
            res += *p;
        int i = 0;
        while(i < res.size() && res[i] == '0')
            i++;
        if(i >= res.size())
            return "0";
        else
            return res.substr(i);
    }
};
