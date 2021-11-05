//
// Created by BrandonZu on 11/5/21.
//

#include "common.h"

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_multimap<string, unordered_set<string>> acct;
        vector<vector<string>> res;
        for(auto& account: accounts) {
            string cur = account[0];
            for(auto p = account.begin() + 1; p != account.end(); p++) {

            }

        }

        return res;
    }
};
