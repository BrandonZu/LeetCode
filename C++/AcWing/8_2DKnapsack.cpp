//
// Created by BrandonZu on 2021/8/7.
//

#include <vector>
#include <iostream>
using namespace std;

const int N = 1010;

int dp[105][105];
int main() {
    int n, v, m;
    cin >> n >> v >> m;
    int vv, mm, ww;
    for(int i = 0; i < n; i++) {
        cin >> vv >> mm >> ww;
        for(int j = m; j >= mm; j--) {
            for(int k = v; k >= vv; k--) {
                dp[j][k] = max(dp[j][k], dp[j - mm][k - vv] + ww);
            }
        }
    }
    cout << dp[m][v] << endl;
    return 0;
}
