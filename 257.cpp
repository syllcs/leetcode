/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
protected:
    void print(const vector<int> &v, vector<string> &res) {
        string s;
        int l = v.size();
        for (int i = 0; i < l-1; i++) {
            s += to_string(v.at(i));
            s += "->";
        }
        s += to_string(v.at(l-1));
        res.push_back(s);
    }
    void dfs(TreeNode* node, vector<int> &v, vector<string> &res) {
        v.push_back(node->val);
        if ((!node->left) && (!node->right)) {
            print(v, res);
        }
        else {
            if (node->left) dfs(node->left, v, res);
            if (node->right) dfs(node->right, v, res);
        }
        v.erase(v.end() - 1);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        vector<int> v;
        dfs(root, v, res);
        return res;
    }
};
