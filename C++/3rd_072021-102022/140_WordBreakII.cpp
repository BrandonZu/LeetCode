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

// 1st Review 12/12/21
// Runtime 0ms(>100%) | Memory Usage 7.3MB(>66%)
class Solution_R1 {
    vector<string> res;
    unordered_set<string> word_set;
public:
    void recur(string path, int l) {
        for(int r = l; r < path.size(); r++) {
            if(word_set.find(path.substr(l, r - l + 1)) != word_set.end()) {
                if(r == path.size() - 1) {
                    res.push_back(path);
                }
                else {
                    string tmp = path;
                    tmp.insert(tmp.begin() + r + 1, ' ');
                    recur(tmp, r + 2);
                }
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto& w: wordDict)
            word_set.insert(w);
        recur(s, 0);
        return res;
    }
};
