//
// Created by BrandonZu on 11/18/21.
//

#include "common.h"

// Runtime 26ms(>79%) | Memory Usage 17.8MB(>85%)
class Solution_1 {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.empty() || mat[0].empty()) return {};
        int n = mat.size(), m = mat[0].size();
        vector<int> res(n * m);
        int i = 0, j = 0;
        for(int cnt = 0; cnt < n * m; cnt++) {
            res[cnt] = mat[i][j];
            if((i + j) % 2 == 1) {
                if(i == n - 1) {
                    j++;
                }
                else if(j == 0) {
                    i++;
                }
                else {
                    i++, j--;
                }
            }
            else {
                if(j == m - 1) {
                    i++;
                }
                else if(i == 0) {
                    j++;
                }
                else {
                    i--, j++;
                }
            }
        }
        return res;
    }
};

// Runtime 66ms(>26%) | Memory Usage 18.4MB(>44%)
class Solution_2 {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.empty() || mat[0].empty()) return {};
        int n = mat.size(), m = mat[0].size();
        vector<int> res;
        vector<int> tmp;
        for(int j = 0; j < m; j++) {
            tmp.clear();
            int x = 0, y = j;
            while(x < n && y >= 0) {
                tmp.push_back(mat[x++][y--]);
            }
            if(j % 2 == 0)
                reverse(tmp.begin(), tmp.end());
            res.insert(res.end(), tmp.begin(), tmp.end());
        }
        for(int i = 1; i < n; i++) {
            tmp.clear();
            int x = i, y = m - 1;
            while(x < n && y >= 0) {
                tmp.push_back(mat[x++][y--]);
            }
            if((m + i) % 2 == 1)
                reverse(tmp.begin(), tmp.end());
            res.insert(res.end(), tmp.begin(), tmp.end());
        }
        return res;
    }
};

// Runtime 44ms(>44%) | Memory Usage 22.5MB(>23%)
class Solution_3 {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> res(n + m - 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res[i + j].push_back(mat[i][j]);
            }
        }
        for(int i = 2; i < n + m - 2; i += 2) {
            reverse(res[i].begin(), res[i].end());
        }
        vector<int> ans;
        for(auto& l: res) {
            ans.insert(ans.end(), l.begin(), l.end());
        }
        return ans;
    }
};

// 1st Review 12/12/21
// Runtime 20ms(>98%) | Memory Usage 17.6MB(>100%)
class Solution_1_R1 {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> res(n * m);
        int i = 0, j = 0;
        for(int cnt = 0; cnt < n * m; cnt++) {
            res[cnt] = mat[i][j];
            if((i + j) % 2 == 1) {
                if(i == n - 1) {
                    j++;
                }
                else if(j == 0) {
                    i++;
                }
                else {
                    i++, j--;
                }
            }
            else {
                if(j == m - 1) {
                    i++;
                }
                else if(i == 0) {
                    j++;
                }
                else {
                    i--, j++;
                }
            }
        }
        return res;
    }
};
