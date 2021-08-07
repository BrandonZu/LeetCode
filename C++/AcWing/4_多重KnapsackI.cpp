//
// Created by BrandonZu on 2021/8/6.
//

#include <iostream>
using namespace std;
const int N = 105;
int n, m;
int v[N], w[N], s[N];
int dp[N];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i] >> s[i];
    }

    // Normal
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= 0; j--) {
            for(int k = 1; k <= s[i] && k * v[i] <= j; k++) {
                dp[j] = max(dp[j], dp[j - k * v[i]] + k * w[i]);
            }
        }
    }

    cout << dp[m] << endl;
    return 0;
}
