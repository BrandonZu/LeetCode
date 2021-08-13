//
// Created by BrandonZu on 2021/8/11.
//

#include <iostream>
#include <vector>
using namespace std;

const int N = 1e6 + 5;
int num[N], s[N];

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> num[i];
        s[i] = s[i - 1] + num[i];
    }
    for(int kk = 0; kk < m; kk++) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}
