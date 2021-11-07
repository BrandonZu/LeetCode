//
// Created by BrandonZu on 11/4/21.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 11MB(>13%)
class Solution {
public:
    string simplifyPath(string path) {
        path += '/';
        vector<string> split;
        int pos = path.find('/');
        int prev = 0;
        while(pos != string::npos) {
            split.push_back(path.substr(prev, pos - prev));
            prev = pos + 1;
            pos = path.find('/', pos + 1);
        }
        vector<string> stk;
        for(string& cur: split) {
            if(cur.empty() || cur == ".") {
                continue;
            }
            else if(cur == "..") {
                if(!stk.empty())
                    stk.pop_back();
            }
            else {
                stk.push_back(cur);
            }
        }
        string ans;
        for(auto& str: stk) {
            ans += '/' + str;
        }
        if(ans.empty())
            return "/";
        else
            return ans;
    }
};

// Runtime 8ms(>56%) | Memory Usage 9.3MB(>62%)
class Solution_2 {
public:
    string simplifyPath(string path) {
        string token;
        vector<string> stk;
        stringstream ss(path);
        while(getline(ss, token, '/')) {
            if(token.empty() || token == ".") {
                continue;
            }
            else if(token == "..") {
                if(!stk.empty())
                    stk.pop_back();
            }
            else {
                stk.push_back(token);
            }
        }
        string ans;
        for(auto& str: stk) {
            ans += '/' + str;
        }
        if(ans.empty())
            return "/";
        else
            return ans;
    }
};
