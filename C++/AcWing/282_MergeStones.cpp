//
// Created by BrandonZu on 2021/8/8.
//

#include <iostream>
#include <vector>
using namespace std;

const int N = 302;
int nums[N], dp[N][N], s[N];

int main() {
    int n;
    cin >> n;
    int tmp = 0;
    for(int i = 1; i <= n; i++) {
        cin >> nums[i];
        tmp += nums[i];
        s[i] = tmp;
    }
    // Init DP Table
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j)
                dp[i][j] = 0;
            else
                dp[i][j] = 1e9;
        }
    }

    for(int len = 2; len <= n; len++) {
        for(int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            for(int k = l; k <= r - 1; k++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    }

    cout << dp[1][n] << endl;
    return 0;
}

