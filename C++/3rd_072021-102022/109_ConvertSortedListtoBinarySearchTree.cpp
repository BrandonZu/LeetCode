//
// Created by BrandonZu on 2021/7/14.
//

#include "iostream"
#include "vector"
#include "queue"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Runtime 24ms(>93%) | Memory Usage 30MB(>90%)
class Solution {
public:
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head, * fast = head;
        ListNode* pre = nullptr;
        while(slow && fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        }
        if(pre) pre->next = nullptr;
        return slow;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return new TreeNode(head->val);

        ListNode* mid = getMid(head);
        TreeNode* root = new TreeNode(mid->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }
};
