//
// Created by BrandonZu on 10/26/21.
//

#include <iostream>
using namespace std;

const int N = 100010;

int n;
int p[N];

// Return the root of the tree && Route Compression
int find(int x) {
    int root = x;
    // Find
    while(p[root] != root) {
        root = p[root];
    }
    // Route Compression
    int parent;
    while(p[x] != x) {
        parent = p[x];
        p[x] = root;
        x = parent;
    }
    return root;
}

int main() {
    cin >> n;
    int m;
    cin >> m;
    for(int i = 0; i < n; i++) p[i] = i;
    char oper;
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> oper >> a >> b;
        if(oper == 'M') {
            p[find(a)] = find(b);
        }
        else {
            if(find(a) == find(b))
                cout << "Yes" << endl;
            else
                cout <<  "No" << endl;
        }
    }
    return 0;
}
