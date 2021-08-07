//
// Created by BrandonZu on 2021/8/7.
//

#include <vector>
#include <iostream>
using namespace std;

const int N = 1005;
int n, m;

struct Good {
    int v, w, s;
    Good(int v, int w, int s): v(v), w(w), s(s) {}
};
vector<Good> goods;
int dp[N];

int main() {
    cin >> n >> m;
    int v, w, s;
    for(int i = 0; i < n; i++) {
        cin >> v >> w >> s;
        if(s == -1 || s == 0) {
            goods.emplace_back(v, w, s);
        }
        else {
            int k = 1;
            while(k <= s) {
                goods.emplace_back(k * v, k * w, -1);
                s -= k;
                k *= 2;
            }
            if(s)
                goods.emplace_back(s * v, s * w, -1);
        }
    }
    // DP
    for(auto good:goods) {
        if(good.s == -1) {
            for(int j = m; j >= good.v; j--)
                dp[j] = max(dp[j], dp[j - good.v] + good.w);
        }
        else {
            for(int j = good.v; j <= m; j++)
                dp[j] = max(dp[j], dp[j - good.v] + good.w);
        }
    }
    cout << dp[m] << endl;
    return 0;
}
