//
// Created by BrandonZu on 2021/8/7.
//

#include <iostream>
using namespace std;

const int N = 1005, MOD = 1e9+7;
int value[N], cnt[N];

int main() {
    int n, m;
    int v, w;
    cin >> n >> m;
    value[0] = 0;
    cnt[0] = 1;
    for(int i = 1; i <= m; i++) {
        value[i] = INT_MIN;
    }
    for(int i = 0; i < n; i++) {
        cin >> v >> w;
        for(int j = m; j >= v; j--) {
            if(value[j] < value[j - v] + w)
                cnt[j] = cnt[j - v];
            else if(value[j] == value[j - v] + w)
                cnt[j] = cnt[j] + cnt[j - v];
            else
                cnt[j] = cnt[j];
            if(cnt[j] > MOD)
                cnt[j] %= MOD;
            value[j] = max(value[j], value[j - v] + w);
        }
    }

    int maxw;
    for(int vv : value) {
        maxw = max(maxw, vv);
    }
    int res = 0;
    for(int i = 0; i <= m; i++) {
        if(value[i] == maxw) {
            res += cnt[i];
            res = res > MOD ? res - MOD : res;
        }
    }
    cout << res << endl;
    return 0;
}

