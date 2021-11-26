//
// Created by BrandonZu on 11/25/21.
//

#include "common.h"

// Runtime 31ms(>38%) | Memory Usage 13MB(>67%)
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> cnt(n, 0);

        stack<pair<int, int>> stk;
        for(string& l: logs) {
            int pos_1 = l.find(':');
            int pos_2 = l.find(':', pos_1 + 1);
            int id = stoi(l.substr(0, pos_1));
            string tag = l.substr(pos_1 + 1, pos_2 - pos_1 - 1);
            int time = stoi(l.substr(pos_2 + 1));

            if(tag == "start") {
                if(stk.empty()) {
                    stk.push({id, time});
                }
                else {
                    cnt[stk.top().first] += time - stk.top().second;
                    stk.push({id, time});
                }
            }
            else {
                cnt[id] += time - stk.top().second + 1;
                stk.pop();
                if(!stk.empty())
                    stk.top().second = time + 1;
            }
        }
        return cnt;
    }
};
