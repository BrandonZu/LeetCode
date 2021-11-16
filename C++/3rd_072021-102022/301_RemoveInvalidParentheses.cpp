//
// Created by BrandonZu on 11/15/21.
//

#include "common.h"

// Runtime 108ms(>55%) | Memory Usage 8.9MB(>79%)
class Solution_DFS {
public:
    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;
        for(char c: s) {
            if(c == '(')
                l++;
            else if(c == ')') {
                if(l > 0)
                    l--;
                else
                    r++;
            }
        }
        unordered_set<string> res;
        string path;
        dfs(s, res, path, 0, 0, l, r);
        return vector<string> (res.begin(), res.end());
    }

    void dfs(string& s, unordered_set<string>& res, string& path, int i, int prefix, int l, int r) {
        if(prefix < 0 || l < 0 || r < 0) return;
        if(i == s.size()) {
            if(prefix == 0 && l == 0 && r == 0)
                res.insert(path);
            return;
        }

        if(s[i] == '(') {
            dfs(s, res, path, i + 1, prefix, l - 1, r);
            path.push_back('(');
            dfs(s, res, path, i + 1, prefix + 1, l, r);
        }
        else if(s[i] == ')') {
            dfs(s, res, path, i + 1, prefix, l, r - 1);
            path.push_back(')');
            dfs(s, res, path, i + 1, prefix - 1, l, r);
        }
        else {
            path.push_back(s[i]);
            dfs(s, res, path, i + 1, prefix, l, r);
        }
        path.pop_back();
    }
};
