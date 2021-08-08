//
// Created by BrandonZu on 2021/8/7.
//

#include <iostream>
using namespace std;
const int N = 1002;
int dp[N][N], v[N], w[N];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }

    for(int i = n; i >= 1; i--) {
        for(int j = 0; j <= m; j++) {
            if(j >= v[i])
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - v[i]] + w[i]);
            else
                dp[i][j] = dp[i + 1][j];
        }
    }

    int cur = m;
    // 字典序最小，所以从前往后看
    for(int i = 1; i <= n; i++) {
        if(dp[i][cur] == dp[i + 1][cur - v[i]] + w[i] && cur >= v[i]) {
            cout << i << ' ';
            cur -= v[i];
        }
    }

    return 0;
}
