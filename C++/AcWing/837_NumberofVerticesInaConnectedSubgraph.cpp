//
// Created by BrandonZu on 10/26/21.
//

#include <iostream>
using namespace std;

const int N = 100005;
int n, m;
int p[N], sz[N];

int find(int x) {
    if(p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void merge(int parent, int child) {
    // Record number of elements in a set
    if(find(parent) == find(child)) return;
    sz[find(parent)] += sz[find(child)];

    p[find(child)] = find(parent);
}

int main() {
    cin >> n >> m;
    // Init
    for(int i = 0; i < n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
    string oper;
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> oper;
        if(oper == "C") {
            cin >> a >> b;
            merge(a, b);
        }
        else if(oper == "Q1") {
            cin >> a >> b;
            if(find(a) == find(b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else if(oper == "Q2") {
            cin >> a;
            cout << sz[find(a)] << endl;
        }
    }
    return 0;
}
