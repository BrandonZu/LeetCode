//
// Created by BrandonZu on 10/26/21.
//

#include "common.h"

// Number of Beads
vector<int> p, sz;

int find(int x) {
    if(p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int numberofBeads(vector<int> A) {
    int n = A.size();
    p.resize(n);
    sz.resize(n);
    for(int i = 0; i < n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
    for(int i = 0; i < n; i++) {
        if(find(i) == find(A[i])) continue;
        sz[find(i)] += sz[find(A[i])];
        p[find(A[i])] = find(i);
    }
    int res = 0;
    for(int i: sz)
        res = max(res, i);
    return res;
}

// Roll Die
int

int main() {
    vector<int> a = {5, 4, 0, 3, 1, 6, 2};
    cout << numberofBeads(a) << endl;
}
