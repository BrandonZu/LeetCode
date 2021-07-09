#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};
/*
class Solution {
    vector<int> cur;
    int pathNum;
    int target;
public:
    void recur(TreeNode* root) {
        if(!root)
            return;
        cur.push_back(root->val);
        int tmp = 0;
        for(auto p = cur.rbegin(); p != cur.rend(); p++) {
            tmp += *p;
            if(tmp == target)
                pathNum++;
        }
        if(root->left)
            recur(root->left);
        if(root->right)
            recur(root->right);
        cur.pop_back();
    }

    int pathSum(TreeNode* root, int sum) {
        pathNum = 0;
        target = sum;
        recur(root);
        return pathNum;
    }
};
*/
class Solution {
    unordered_map<int, int> dict;
    int curSum;
    int target;
public:
    int recurPathSum(TreeNode* root) {
        if(!root)
            return 0;
        int res = 0;
        curSum += root->val;
        res += dict[curSum - target];
        dict[curSum] += 1;
        res += recurPathSum(root->left);
        res += recurPathSum(root->right);
        dict[curSum] -= 1;
        curSum -= root->val;
        return res;
    }

    int pathSum(TreeNode* root, int sum) {
        curSum = 0;
        target = sum;
        dict[0] = 1;
        return recurPathSum(root);
    }
};