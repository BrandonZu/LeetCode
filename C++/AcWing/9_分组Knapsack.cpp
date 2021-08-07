//
// Created by BrandonZu on 2021/8/7.
//

#include <iostream>
using namespace std;

const int N = 102;
int dp[N], v[N], w[N];

// dp[j] 前i组，用j个物品
int main() {
    int n, vol;
    cin >> n >> vol;
    int s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < s; j++) {
            cin >> v[j] >> w[j];
        }
        for(int j = vol; j >= 0; j--) {
            for(int k = 0; k < s; k++) {
                if(v[k] <= j)
                    dp[j] = max(dp[j], dp[j - v[k]] + w[k]);
            }
        }
    }
    cout << dp[vol] << endl;
    return 0;
}

