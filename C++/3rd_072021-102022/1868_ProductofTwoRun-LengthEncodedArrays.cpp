//
// Created by BrandonZu on 11/27/21.
//

#include "common.h"

// Runtime 524ms(>84%) | Memory Usage 204MB(>95%)
class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        vector<vector<int>> res;
        int i = 0, j = 0, n = encoded1.size(), m = encoded2.size();
        int num1 = 0, num2 = 0;
        while(i < n && j < m) {
            if(num1 == 0) {
                num1 = encoded1[i][1];
            }
            if(num2 == 0) {
                num2 = encoded2[j][1];
            }
            int cur_num = encoded1[i][0] * encoded2[j][0];
            int cur_cnt = min(num1, num2);
            if(res.size() && res.back()[0] == cur_num) {
                res.back()[1] += cur_cnt;
            }
            else {
                res.push_back({cur_num, cur_cnt});
            }
            num1 -= cur_cnt, num2 -= cur_cnt;
            if(num1 == 0) i++;
            if(num2 == 0) j++;
        }
        return res;
    }
};

class Solution_TLE {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        vector<int> num1, num2;
        for(auto p = encoded1.rbegin(); p != encoded1.rend(); p++) {
            for(int i = 0; i < (*p)[1]; i++) {
                num1.push_back((*p)[0]);
            }
        }
        for(auto p = encoded2.rbegin(); p != encoded2.rend(); p++) {
            for(int i = 0; i < (*p)[1]; i++) {
                num2.push_back((*p)[0]);
            }
        }
        vector<int> res(num1.size(), 0);
        for(int i = 0; i < num1.size(); i--) {
            res[i] = num1[i] * num2[i];
        }
        vector<vector<int>> encoded;
        int pos = res.size() - 1;
        while(res[pos] == 0 && pos > 0) pos--;
        while(pos >= 0) {
            int j;
            for(j = pos; j >= 0 && res[j] == res[pos]; j--) {}
            encoded.push_back({res[pos], pos - j});
            pos = j;
        }
        return encoded;
    }
};
