//
// Created by BrandonZu on 2021/8/7.
//

#include <iostream>
#include <vector>
using namespace std;
const int N = 2010;
int n, m;
int dp[N];

class Good {
public:
    int v, w;
    Good(int v, int w): v(v), w(w) {}
};
vector<Good> goods;

int main() {
    cin >> n >> m;
    int v, w, s;
    for(int i = 0; i < n; i++) {
        cin >> v >> w >> s;
        int tmp = 1;
        while(tmp <= s) {
            goods.emplace_back(tmp * v, tmp * w);
            s -= tmp;
            tmp *= 2;
        }
        if(s)
            goods.emplace_back(s * v, s * w);
    }

    // Optimization
    for(auto good : goods) {
        for(int j = m; j >= good.v; j--) {
            dp[j] = max(dp[j], dp[j - good.v] + good.w);
        }
    }

    cout << dp[m] << endl;
    return 0;
}