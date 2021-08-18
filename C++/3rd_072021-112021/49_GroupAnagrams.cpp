//
// Created by BrandonZu on 2021/8/18.
//

#include "common.h"

// Runtime 28ms(>92%) | Memory Usage 18MB(>91%)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash_str;
        for(int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            hash_str[tmp].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for(auto& item: hash_str) {
            res.push_back(move(item.second));
        }
        return res;
    }
};

// Runtime 32ms(>80%) | Memory Usage 18MB(>97%)
class Solution_2 {
public:
    static bool myCmp(const pair<string, int>& a, const pair<string, int>& b) {
        return a.first < b.first;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;

        vector<pair<string, int>> sorted_strs;
        for(int i = 0; i < strs.size(); i++) {
            string cur(strs[i]);
            sort(cur.begin(), cur.end());
            sorted_strs.emplace_back(cur, i);
        }
        sort(sorted_strs.begin(), sorted_strs.end(), myCmp);

        int pos = 0;
        vector<string> cur;
        while(pos < strs.size()) {
            cur.clear();
            // Find matched strings
            cur.push_back(strs[sorted_strs[pos].second]);
            int origin = pos;
            pos++;
            while(pos < strs.size()) {
                if(sorted_strs[pos].first != sorted_strs[origin].first)
                    break;
                else
                    cur.push_back(strs[sorted_strs[pos].second]);
                pos++;
            }
            res.push_back(cur);
        }
        return res;
    }
};
