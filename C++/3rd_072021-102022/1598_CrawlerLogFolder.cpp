//
// Created by BrandonZu on 11/3/21.
//

#include "common.h"

// Runtime 8ms(>51%) | Memory Usage 10.6MB(>36%)
class Solution {
public:
    int minOperations(vector<string>& logs) {
        list<string> dir;
        dir.emplace_back("root");
        auto p = dir.begin();
        for(string& log: logs) {
            if(log == "../") {
                if(p != dir.begin())
                    p = prev(p);
            }
            else if(log == "./") {
                p = p;
            }
            else {
                log.pop_back();
                if(next(p) == dir.end()) {
                    dir.push_back(log);
                }
                p = next(p);
            }
        }
        int ans = 0;
        while(p != dir.begin()) {
            p = prev(p);
            ans++;
        }
        return ans;
    }
};

// Runtime 8ms(>51%) | Memory Usage 10.4MB(>67%)
class Solution_2 {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(string& log: logs) {
            if(log == "../")
                ans = max(0, ans - 1);
            else if(log != "./")
                ans++;
        }
        return ans;
    }
};

