//
// Created by BrandonZu on 12/7/21.
//

#include "common.h"

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// Runtime 42ms(>5%) | Memory Usage 10.9MB(>47%)
class Solution {
    int cur_max;
public:
    int dfs(Node* r) {
        if(!r) return 0;
        int max1 = 0, max2 = 0;
        for(auto child: r->children) {
            int tmp = dfs(child);
            if(tmp > max1) {
                max2 = max1;
                max1 = tmp;
            }
            else if(tmp > max2) {
                max2 = tmp;
            }
        }
        cur_max = max(cur_max, max1 + max2);
        return max1 + 1;
    }

    int diameter(Node* root) {
        cur_max = 0;
        dfs(root);
        return cur_max;
    }
};
