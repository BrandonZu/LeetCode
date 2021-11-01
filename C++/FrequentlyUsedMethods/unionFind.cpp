//
// Created by BrandonZu on 10/31/21.
//

#include "common.h"
const int N = 100;
int p[N], sz[N];

int find(int x) {
    if(p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void merge(int parent, int child) {
    if(find(parent) == find(child))
        return;
    // Record number of elements in a set
    sz[find(parent)] += sz[find(child)];
    // Merge two sets
    p[find(child)] = find(parent);
}
