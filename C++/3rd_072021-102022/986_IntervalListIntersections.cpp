//
// Created by BrandonZu on 12/11/21.
//

#include "common.h"

// Runtime 36ms(>64%) | Memory Usage 18.8MB(>44%)
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size(), m = secondList.size();
        vector<vector<int>> res;
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(firstList[i][1] < secondList[j][1]) {
                if(max(firstList[i][0], secondList[j][0]) <= firstList[i][1])
                    res.push_back({max(firstList[i][0], secondList[j][0]), firstList[i][1]});
                i++;
            }
            else {
                if(max(firstList[i][0], secondList[j][0]) <= secondList[j][1])
                    res.push_back({max(firstList[i][0], secondList[j][0]), secondList[j][1]});
                j++;
            }
        }
        return res;
    }
};
