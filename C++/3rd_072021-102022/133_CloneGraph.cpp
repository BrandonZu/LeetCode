//
// Created by BrandonZu on 11/27/21.
//

#include "common.h"

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// Runtime 7ms(>61%) | Memory Usage 9MB(>23%)
class Solution {
    unordered_map<int, Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        Node* cur = new Node(node->val);
        visited[cur->val] =  cur;
        for(auto p: node->neighbors) {
            if(visited.find(p->val) == visited.end())
                cur->neighbors.push_back(cloneGraph(p));
            else
                cur->neighbors.push_back(visited[p->val]);
        }
        return cur;
    }
};

// R .100 | M .53
class Solution2 {
public:
    unordered_map<int, Node*> createdNode;
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        Node* newNode = new Node(node->val);
        createdNode[node->val] = newNode;
        for(auto i : node->neighbors) {
            if(createdNode.find(i->val) == createdNode.end())
                newNode->neighbors.push_back(cloneGraph(i));
            else
                newNode->neighbors.push_back(createdNode[i->val]);
        }
        return newNode;
    }
};