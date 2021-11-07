//
// Created by BrandonZu on 10/3/21.
//

#include "common.h"

// Runtime 60ms(>89%) | Memory Usage 17.2MB(>67%)
class Solution {
public:
    bool check(string& a, string& b) {
        if(abs((int)a.size() - (int)b.size()) != 1) return false;
        if(a.size() > b.size()) return check(b, a);
        int i = 0, j = 0;
        bool flag = true;
        while(i < a.size() && j < b.size()) {
            if(a[i] == b[j]) {
                ++i, ++j;
            }
            else {
                if(!flag) return false;
                flag = false;
                ++j;
            }
        }
        return true;
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [&] (const string& a, const string& b) {return a.size() < b.size();});
        unordered_map<string, int> lengthMap;
        // Base case
        for(auto& s: words)
            lengthMap[s] = 1;
        for(auto& s: words) {
            for(int i = 0; i < s.size(); i++) {
                string pre = s.substr(0, i) + s.substr(i + 1);
                if(lengthMap.find(pre) != lengthMap.end()) {
                    lengthMap[s] = max(lengthMap[s], lengthMap[pre] + 1);
                }
            }
        }
        // Find max length
        int res = 1;
        for(auto i: lengthMap) {
            res = max(res, i.second);
        }
        return res;
    }
};
