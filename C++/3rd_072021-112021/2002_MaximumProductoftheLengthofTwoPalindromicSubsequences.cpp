//
// Created by BrandonZu on 11/2/21.
//

#include "common.h"

// Runtime 756ms(>30%) | Memory Usage 234MB(>7%)
class Solution_1 {
public:
    int maxProduct(string s) {
        int n = s.size();
        int ret = 0;
        for(int subset = 1; subset < (1 << n) - 1; subset++) {
            ret = max(ret, lps(s, subset) * lps(s, (1 << n) - 1 - subset));
        }
        return ret;
    }

    int lps(string& s, int subset) {
        string cur;
        for(int i = 0; i < s.size(); i++) {
            if((subset >> i) & 1) {
                cur.push_back(s[s.size() - 1 - i]);
            }
        }

        int n = cur.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if(cur[i] == cur[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};

// Runtime 348ms(>55%) | Memory Usage 6MB(>75%)
class Solution_2 {
    int max_result = 0;
public:
    bool isPalindrome(string& a) {
        if(a.size() <= 1) return true;
        int l = 0, r = a.size() - 1;
        while(l < r) {
            if(a[l] != a[r])
                return false;
            l++, r--;
        }
        return true;
    }

    void dfs(const string& s, int pos, string& s1, string& s2) {
        if(pos >= s.size()) {
            if(isPalindrome(s1) && isPalindrome(s2)) {
                max_result = max(max_result, (int)s1.size() * (int)s2.size());
            }
            return;
        }

        s1.push_back(s[pos]);
        dfs(s, pos + 1, s1, s2);
        s1.pop_back();

        s2.push_back(s[pos]);
        dfs(s, pos + 1, s1, s2);
        s2.pop_back();

        dfs(s, pos + 1, s1, s2);
    }

    int maxProduct(string s) {
        string s1, s2;
        dfs(s, 0, s1, s2);
        return max_result;
    }
};