//
// Created by BrandonZu on 11/7/21.
//

#include "common.h"

vector<int> parent;

int find(int x) {
    if(parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void merge(int p, int child) {
    if(find(p) != find(child))
        parent[find(child)] = find(p);
}

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    parent.resize(g_nodes + 1);
    for(int i = 0; i <= g_nodes; i++) parent[i] = i;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = 0; i < g_weight.size(); i++) {
        pq.push({g_weight[i], i});
    }

    int edge_cnt = 0;
    int edge_sum = 0;
    while (edge_cnt < g_nodes - 1) {
        auto edge = pq.top();
        pq.pop();
        if(find(g_from[edge.second]) != find(g_to[edge.second])) {
            merge(g_from[edge.second], g_to[edge.second]);
            edge_cnt++;
            edge_sum += edge.first;
        }
    }

    return edge_sum;
}

int main() {
    vector<int> from = {1, 1, 4, 2, 3, 3}, to = {2, 3, 1, 4, 2, 4}, g_weight = {5, 3, 6, 7, 4, 5};
    cout << kruskals(4, from, to, g_weight);
    return 0;
}
