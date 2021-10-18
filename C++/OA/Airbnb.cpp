//
// Created by BrandonZu on 10/16/21.
//

#include "common.h"

// Leetcdoe 166
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans;
        // Corner Cases
        if(numerator == 0) return "0";
        if(numerator < 0 ^ denominator < 0) ans += '-';

        long n = labs(numerator), d = labs(denominator);
        ans += to_string(n / d);
        long remain = n % d;
        if(remain == 0) return ans;
        ans += '.';

        unordered_map<int, int> remainSet;
        while(remain) {
            if(remainSet.find(remain) != remainSet.end()) {
                ans.insert(remainSet[remain], "(");
                ans += ')';
                break;
            }
            remainSet[remain] = ans.size();
            remain *= 10;
            ans += to_string(remain / d);
            remain = remain % d;
        }
        return ans;
    }
};

// Application Build Cost
//BFS

// 有向图反转 + DFS
// Course Schedule
class Solution {
    vector<int> ans;
    vector<int> status;
    vector<vector<int>> adj;
    bool flag;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        status.resize(numCourses, 0);
        adj.resize(numCourses);
        flag = true;
        // Build Graph
        for(auto& req: prerequisites) {
            adj[req[0]].push_back(req[1]);
        }
        // DFS
        for(int i = 0; i < numCourses; i++) {
            if(status[i] == 0) {
                dfs(i);
            }
        }
        if(flag)
            return ans;
        else
            return {};
    }

    void dfs(int cur) {
        if(!flag) return;

        status[cur] = 1;
        for(int node: adj[cur]) {
            if(status[node] == 0) {
                dfs(node);
            }
            else if(status[node] == 1) {
                flag = false;
                return;
            }
            else if(status[node] == 2) {
                continue;
            }
        }
        status[cur] = 2;
        ans.push_back(cur);
    }
};

// Leetcode 875
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1, r = 1e9;
        while(l < r) {
            int mid = (l + r) / 2;
            int totalTime = 0;
            for(int i: piles)
                totalTime += (i + mid - 1) / mid;
            if(totalTime <= h) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};
