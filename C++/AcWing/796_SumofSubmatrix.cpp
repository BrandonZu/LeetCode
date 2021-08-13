//
// Created by BrandonZu on 2021/8/11.
//

#include <iostream>
using namespace std;

const int N = 1004;

int bd[N][N], s[N][N];

int main() {
    ios::sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> bd[i][j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + bd[i][j];
        }
    }

    int x1, y1, x2, y2;
    for(int ii = 0; ii < q; ii++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] << endl;
    }
    return 0;
}

