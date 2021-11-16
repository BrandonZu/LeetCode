//
// Created by BrandonZu on 11/15/21.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 7.3MB(>66%)
class Solution {
    vector<string> result;
    unordered_set<string> hash_set;
public:
    void recurse(string s, int l) {
        for(int r = l; r < s.size(); r++) {
            if(hash_set.find(s.substr(l, r - l + 1)) != hash_set.end()) {
                if(r == s.size() - 1) {
                    result.push_back(s);
                }
                else {
                    string tmp = s;
                    tmp.insert(tmp.begin() + r + 1, ' ');
                    recurse(tmp, r + 2);
                }
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string& str: wordDict) {
            hash_set.insert(str);
        }
        recurse(s, 0);
        return result;
    }
};
