//
// Created by BrandonZu on 11/14/21.
//

#include "common.h"
#include "TreeNode.h"

// Runtime 36ms(>78%) | Memory Usage 25MB(>95%)
class Solution {
public:
    TreeNode* str2tree(string s) {
        if(s.empty()) return nullptr;
        stack<TreeNode*> stk;
        int i = 0;
        while(i < s.size() && s[i] != '(' && s[i] != ')')
            i++;
        TreeNode* head = new TreeNode(stoi(s.substr(0, i)));
        stk.push(head);
        while(i < s.size()) {
            if(s[i] == ')') {
                i++;
                stk.pop();
            }
            else if(s[i] == '(') {
                i++;
            }
            else {
                int j = i;
                while(i < s.size() && s[i] != '(' && s[i] != ')')
                    i++;
                TreeNode* cur = new TreeNode(stoi(s.substr(j, i - j)));
                if(stk.top()->left)
                    stk.top()->right = cur;
                else
                    stk.top()->left = cur;
                stk.push(cur);
            }
        }
        return stk.top();
    }
};
