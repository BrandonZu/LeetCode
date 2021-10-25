//
// Created by BrandonZu on 10/24/21.
//

#include "common.h"

// Runtime 1066ms(>21%) | Memory Usage 40MB(>80%)
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));
        vector<int> count(n + 1, 0);
        for(auto& edge: edges) {
            graph[edge[0]][edge[1]] = true;
            graph[edge[1]][edge[0]] = true;
            count[edge[0]]++;
            count[edge[1]]++;
        }
        int result = INT_MAX;
        for(int p = 1; p <= n; p++) {
            for(int i = 1; i <= n; i++) {
                if(graph[p][i]) {
                    for(int j = i + 1; j <= n; j++) {
                        if(graph[i][j] && graph[p][j])
                            result = min(result, count[i] + count[j] + count[p] - 6);
                    }
                }
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};
