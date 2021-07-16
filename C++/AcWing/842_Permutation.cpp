//
// Created by BrandonZu on 2021/7/15.
//

#include<iostream>
using namespace std;

const int N = 10;
int path[N];
int n;
bool st[N];

void dfs(int pos) {
    if(pos == n) {
        for(int i = 0; i <= n - 1; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(!st[i]) {
            path[pos] = i;
            st[i] = true;
            dfs(pos + 1);
            st[i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(0);
    return 0;
}
