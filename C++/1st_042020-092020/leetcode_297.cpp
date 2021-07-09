#include <cstring>
#include <vector>
#include <string>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * 前序遍历实现
class Codec {
public:

    vector<string> my_split(string data) {
        size_t start = 0;
        vector<string> result;
        while(start < data.size()) {
            auto pos = data.find(',', start);
            if(pos == string::npos)
                break;
            result.push_back(data.substr(start, pos - start));
            start = pos + 1;
        }
        return move(result);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        dfs(result, root);
        return result;
    }

    void dfs(string& data, TreeNode* root) {
        if(!root) {
            data += "null,";
            return;
        }
        data += to_string(root->val);
        data += ',';
        dfs(data, root->left);
        dfs(data, root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes_list = my_split(data);
        if(nodes_list.empty())
            return NULL;
        TreeNode* root = NULL;
        re_dfs(nodes_list, 1, root);
        return root;
    }

    int re_dfs(vector<string>& data, int pos, TreeNode* root) {
        if(data[pos] == "null") {
            root = NULL;
            return pos+1;
        }
        else {
            root = new TreeNode(stoi(data[pos]));
        }
        int left = re_dfs(data, pos+1, root->left);
        int right = re_dfs(data, left, root->right);
        return right;
    }

};
*/

/*
// BFS实现

class Codec {
public:
    vector<string> my_split(string data) {
        size_t start = 0;
        vector<string> result;
        while(start < data.size()) {
            auto pos = data.find(',', start);
            if(pos == string::npos)
                break;
            result.push_back(data.substr(start, pos - start));
            start = pos + 1;
        }
        return move(result);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        string result;
        while(!node_queue.empty()) {
            TreeNode* tmp = node_queue.front();
            node_queue.pop();
            if(tmp) {
                result += to_string(tmp->val);
                result += ',';
                node_queue.push(tmp->left);
                node_queue.push(tmp->right);
            } else result += "null,";
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> node_list = my_split(data);
        if(node_list[0] == "null")
            return NULL;
        TreeNode* root = new TreeNode(stoi(node_list[0]));
        queue<TreeNode*> rebuild;
        rebuild.push(root);
        for(int i = 1; i < node_list.size(); i++) {
            if(node_list[i] != "null") {
                TreeNode* tmp = new TreeNode(stoi(node_list[i]));
                rebuild.push(tmp);
                rebuild.front()->left = tmp;

            }
            ++i;
            if(node_list[i] != "null") {
                TreeNode* tmp = new TreeNode(stoi(node_list[i]));
                rebuild.push(tmp);
                rebuild.front()->right = tmp;

            }
            rebuild.pop();
        }
        return root;
    }
};
*/

/*
中序遍历，难以定位根结点
class Codec {
public:
    vector<string> my_split(string data) {
        size_t start = 0;
        vector<string> result;
        while(start < data.size()) {
            auto pos = data.find(',', start);
            if(pos == string::npos)
                break;
            result.push_back(data.substr(start, pos - start));
            start = pos + 1;
        }
        return move(result);
    }

    void dfs1(TreeNode* root, string& res) {
        if(!root) {
            res += "null,";
            return;
        }
        dfs1(root->left, res);
        res += to_string(root->val) + ',';
        dfs1(root->right, res);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        dfs1(root, result);
        return result;
    }

    TreeNode* dfs2(const vector<string>& data, int& pos) {
        if(pos == data.size() || data[pos] == "null") {
            pos++;
            return nullptr;
        }
        auto left = dfs2(data, pos);
        TreeNode* root = new TreeNode(stoi(data[pos]));
        pos++;
        auto right = dfs2(data, pos);
        root->left = left;
        root->right = right;
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        auto datas = my_split(data);
        int pos = 0;
        return dfs2(datas, pos);
    }
};
*/

int main() {
    TreeNode* root = new TreeNode(12);
    root->left = new TreeNode(11);
    root->right = new TreeNode(13);
    Codec tmp;
    string res;
    res = tmp.serialize(root);
    auto r = tmp.deserialize(res);
    return 0;
}