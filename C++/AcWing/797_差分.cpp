//
// Created by BrandonZu on 2021/8/13.
//

#include <iostream>
using namespace std;

const int N = 1e5 + 5;
int num[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> num[i];
        b[i] = num[i] - num[i - 1];
    }
    int l, r, c;
    for(int i = 0; i < m; i++) {
        cin >> l >> r >> c;
        b[l] += c;
        b[r + 1] -= c;
    }
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += b[i];
        cout << sum << ' ';
    }
    return 0;
}
