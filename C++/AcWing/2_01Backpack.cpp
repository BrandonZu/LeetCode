#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 1001;

int v[N], w[N];
int dp[N];

int main() {

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    cout << dp[m] << endl;

    return 0;
}

