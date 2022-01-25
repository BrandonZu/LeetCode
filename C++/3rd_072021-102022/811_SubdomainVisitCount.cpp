//
// Created by BrandonZu on 1/25/22.
//

#include "common.h"

// Runtime 12ms(>92%) | Memory Usage 11.4MB(>92%)
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> domain_cnt;

        for(auto& s: cpdomains) {
            int pos = s.find_first_of(' ');
            int cnt = stoi(s.substr(0, pos));
            domain_cnt[s.substr(pos + 1)] += cnt;
            while((pos = s.find_first_of('.', pos + 1)) != string::npos) {
                domain_cnt[s.substr(pos + 1)] += cnt;
            }
        }

        vector<string> res;
        for(auto [k, v]: domain_cnt) {
            res.push_back(to_string(v) + " " + k);
        }
        return res;
    }
};
