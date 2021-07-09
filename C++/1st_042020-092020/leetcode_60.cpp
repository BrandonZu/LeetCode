#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int dp[10];
    string getPermutation(int n, int k) {
        k--;

        int cur = 1;
        dp[0] = 1;
        for(int i = 1; i < n; i++) {
            cur *= i;
            dp[i] = cur;
        }
        vector<int> remain;
        for(int i = 1; i <= n; i++) {
            remain.push_back(i);
        }
        string res = "";
        for(int i = n - 1; i >= 0; i--) {
            int index = k / dp[i];
            k -= index * dp[i];
            auto pos = remain.begin() + index;
            res += '0' + *pos;
            remain.erase(pos);
        }
        return res;
    }
};

int main() {
    Solution test;
    cout << test.getPermutation(4, 9) << endl;
    return 0;
}

