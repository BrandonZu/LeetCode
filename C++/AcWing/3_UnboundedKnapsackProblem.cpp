//
// Created by BrandonZu on 2021/8/1.
//

#include <iostream>
using namespace std;

const int N = 1002;
int n, m;
int v[N], w[N];
int dp1[N][N];
int dp[N];

// DP Transfer Equation
// dp[i][j] = max(dp[i - 1][j], dp[i][j - v[i]] + w[i])
void dp_normal() {
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            dp1[i][j] = dp1[i - 1][j];
            if(j >= v[i])
                dp1[i][j] = max(dp1[i][j], dp1[i][j - v[i]] + w[i]);
        }
    }
    cout << dp1[n][m] << endl;
}

void dp_optimized() {
    for(int i = 1; i <= n; i++) {
        for(int j = v[i]; j <= m; j++) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[m] << endl;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> v[i + 1] >> w[i + 1];
    }
    dp_optimized();

    return 0;
}
