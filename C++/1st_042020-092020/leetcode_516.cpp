#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int i = 0; i < s.size(); i++)
            dp[i][i] = 1;
        for(int j = 1; j < s.size(); j++) {
            for(int i = j - 1; i >= 0; i--) {
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};

int main() {
    string test = "bbab";
    Solution tmp;
    tmp.longestPalindromeSubseq(test);
    return 0;
}