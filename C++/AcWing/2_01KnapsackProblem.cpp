#include "common.h"
using namespace std;

const int N = 1001;

int n, m;
int v[N], w[N];
int dp1[N][N];
int dp2[N];

// DP Transfer Equation
// dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i])

void dp_normal() {
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(j < v[i])
                dp1[i][j] = dp1[i - 1][j];
            else
                dp1[i][j] = max(dp1[i - 1][j], dp1[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << dp1[n][m] << endl;
}

void dp_optimized() {
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= v[i]; j--) {
            dp2[j] = max(dp2[j], dp2[j - v[i]] + w[i]);
        }
    }
    cout << dp2[m] << endl;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    dp_normal();

    return 0;
}

