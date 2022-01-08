//
// Created by BrandonZu on 11/3/21.
//

#include "common.h"

inline int getDist(const vector<int>& a) {
    return a[0] * a[0] + a[1] * a[1];
}

// Runtime 264ms(>43%) | Memory Usage 60MB(>44%)
class Solution_1 {
public:
    struct cmp{
        bool operator() (vector<int>& a, vector<int>& b) {
            return getDist(a) < getDist(b);
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        for(auto& p: points) {
            if(pq.size() < k) {
                pq.push(p);
            }
            else if(getDist(pq.top()) > getDist(p)) {
                pq.pop();
                pq.push(p);
            }
        }
        vector<vector<int>> result;
        while(!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};

// Runtime 232ms(>52%) | Memory Usage 60MB(>46%)
class Solution_2 {
public:
    struct cmp{
        bool operator() (vector<int>& a, vector<int>& b) {
            return getDist(a) > getDist(b);
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq(points.begin(), points.end());
        vector<vector<int>> result;
        for(int i = 0; i < k; i++) {
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};

// 1st Review 12/13/21
// Runtime 232ms(>44%) | Memory Usage 58MB(>54%)
class Solution_R1 {
public:
    struct cmp {
        bool operator() (const vector<int>& a, const vector<int>& b) {
            return getDist(a) > getDist(b);
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq(points.begin(), points.end());
        vector<vector<int>> res(k);
        for(int i = 0; i < k; i++) {
            res[i] = pq.top();
            pq.pop();
        }
        return res;
    }
};

