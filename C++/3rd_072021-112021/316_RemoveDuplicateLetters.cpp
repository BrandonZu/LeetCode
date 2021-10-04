//
// Created by BrandonZu on 10/3/21.
//

#include "common.h"

// Runtime 4ms(>62%) | Memory Usage 6.9MB(>39%)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res;
        unordered_map<char, int> indexMap;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(indexMap.find(s[i]) == indexMap.end()) {
                indexMap[s[i]] = i;
            }
        }
        stack<int> stk;
        unordered_set<char> existSet;
        for(int i = 0; i < s.size(); i++) {
            // Current character already exists
            if(existSet.find(s[i]) != existSet.end()) {
                continue;
            }
            // Delete all characters that are larger than s[i] and not the last one
            while(!stk.empty() && s[stk.top()] > s[i] && stk.top() < indexMap[s[stk.top()]] && i < indexMap[s[stk.top()]]) {
                existSet.erase(s[stk.top()]);
                stk.pop();
            }
            existSet.insert(s[i]);
            stk.push(i);
        }
        while(!stk.empty()) {
            res += s[stk.top()];
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
