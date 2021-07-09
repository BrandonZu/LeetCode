#include <iostream>
#include <deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursion
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return judge(root, root);
    }
    static bool judge(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)
            return true;
        if(!root1 || !root2)
            return false;
        return root1->val == root2->val && judge(root1->left, root2->right) && judge(root1->right, root2->left);
    }
};

// Iteration
/*
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        deque<TreeNode*> judge;
        judge.push_back(root);
        while(!judge.empty()) {
            auto p = judge.begin();
            auto q = judge.rbegin();
            while(p != judge.end() && (p - judge.begin() < (judge.size() + 1) / 2)) {
                if(*p == nullptr && *q != nullptr)
                    return false;
                if(*p != nullptr && *q == nullptr)
                    return false;
                if(*p && *q && (*p)->val != (*q)->val)
                    return false;
                p++;
                q++;
            }
            int len = judge.size();
            for(int i = 0; i < len; i++) {
                TreeNode* tmp = judge.front();
                judge.pop_front();
                if(tmp != nullptr) {
                    judge.push_back(tmp->left);
                    judge.push_back(tmp->right);
                }
            }
        }
        return true;
    }
};
*/
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = nullptr;
    root->right = new TreeNode(2);
    Solution tmp;
    cout << tmp.isSymmetric(root) << endl;
    return 0;
}
