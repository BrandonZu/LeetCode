//
// Created by BrandonZu on 11/14/21.
//

#include "common.h"

// Runtime 4ms(>82%) | Memory Usage 8MB(>80%)
class Solution_OP {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> str_map;
        for(string& s: strings) {
            str_map[shift(s)].push_back(s);
        }
        vector<vector<string>> res;
        for(auto& p: str_map) {
            res.push_back(p.second);
        }
        return res;
    }

    string shift(string& s) {
        string tmp;
        for(int i = 1; i < s.size(); i++) {
            tmp.push_back('a' + (s[i] - s[i - 1] + 26) % 26);
        }
        return tmp;
    }
};

// Runtime 4ms(>82%) | Memory Usage 8.5MB(>17%)
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<pair<string, vector<int>>> str;
        for(string& s: strings) {
            vector<int> tmp;
            for(int i = 1; i < s.size(); i++) {
                tmp.push_back((s[i] - s[i - 1] + 26) % 26);
            }
            str.emplace_back(s, tmp);
        }
        sort(str.begin(), str.end(), [&] (pair<string, vector<int>>& a, pair<string, vector<int>>& b) {
            if(a.first.length() != b.first.length()) {
                return a.first.length() < b.first.length();
            }
            return a.second < b.second;
        });

        int i = 0;
        vector<vector<string>> res;
        while(i < str.size()) {
            vector<string> tmp;
            while(i + 1 < str.size() && str[i].second == str[i + 1].second) {
                tmp.push_back(str[i].first);
                i++;
            }
            tmp.push_back(str[i].first);
            res.push_back(tmp);
            i++;
        }
        return res;
    }
};

// 1st Review 12/12/21
// Runtime 4ms(>81%) | Memory Usage 7.8MB(>90%)
class Solution_R2 {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> str_map;
        for(string& s: strings) {
            str_map[shift(s)].push_back(s);
        }
        for(auto& p: str_map) {
            res.push_back(p.second);
        }
        return res;
    }

    string shift(string str) {
        int d = str[0] - 'a';
        for(auto& c: str) {
            int cur = c - 'a';
            c = (cur - d + 26) % 26 + 'a';
        }
        return str;
    }
};
