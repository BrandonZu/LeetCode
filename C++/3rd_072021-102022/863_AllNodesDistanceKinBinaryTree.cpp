//
// Created by BrandonZu on 11/27/21.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 4ms(>87%) | Memory Usage 13MB(>45%)
class Solution {
    unordered_map<TreeNode*, TreeNode*> toParent;
    unordered_set<TreeNode*> visited;
public:
    void dfs(TreeNode* root) {
        if(root->left) {
            toParent[root->left] = root;
            dfs(root->left);
        }
        if(root->right) {
            toParent[root->right] = root;
            dfs(root->right);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root);
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        while(!q.empty() && k) {
            int sz = q.size();
            k--;
            for(int i = 0; i < sz; i++) {
                auto p = q.front();
                q.pop();
                if(p != root && visited.find(toParent[p]) == visited.end())
                    q.push(toParent[p]), visited.insert(toParent[p]);
                if(p->left && visited.find(p->left) == visited.end())
                    q.push(p->left), visited.insert(p->left);
                if(p->right && visited.find(p->right) == visited.end())
                    q.push(p->right), visited.insert(p->right);
            }
        }
        vector<int> res;
        while(!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};

class Wrong {
public:
    vector<int> bfs(queue<TreeNode*>& q, int depth) {
        vector<int> result;
        while(!q.empty() && depth) {
            depth--;
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto p = q.front();
                q.pop();
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
        }
        while(!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(target == root) {
            queue<TreeNode*> q;
            q.push(root);
            return bfs(q, k);
        }
        if(k == 0) {
            return {target->val};
        }
        // Find Target
        queue<pair<TreeNode*, bool>> q;
        if(root->left) q.push({root->left, false});
        if(root->right) q.push({root->right, true});
        int depth = 0;
        bool found = false, pos = false;
        while(!q.empty() && !found) {
            depth++;
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto p = q.front();
                if(p.first == target) {
                    found = true;
                    pos = p.second;
                    break;
                }
                q.pop();
                if(p.first->left) q.push({p.first->left, p.second});
                if(p.first->right) q.push({p.first->right, p.second});
            }
        }
        queue<TreeNode*> q2;
        q2.push(target);
        vector<int> res = bfs(q2, k);
        if(depth == k) {
            res.push_back(root->val);
            return res;
        }

        if(!pos && root->right && depth < k) {
            queue<TreeNode*> right;
            right.push(root->right);
            vector tmp = bfs(right, k - depth - 1);
            res.insert(res.end(), tmp.begin(), tmp.end());
        }
        else if(pos && root->left && depth < k) {
            queue<TreeNode*> left;
            left.push(root->left);
            vector tmp = bfs(left, k - depth - 1);
            res.insert(res.end(), tmp.begin(), tmp.end());
        }

        if(pos && depth > k) {
            queue<TreeNode*> right;
            right.push(root->right);
            vector tmp = bfs(right, depth - k - 1);
            res.insert(res.end(), tmp.begin(), tmp.end());
        }
        else if(!pos && depth > k) {
            queue<TreeNode*> left;
            left.push(root->left);
            vector tmp = bfs(left, depth - k - 1);
            res.insert(res.end(), tmp.begin(), tmp.end());
        }

        return res;
    }
};
