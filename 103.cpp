/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
    void dfs(TreeNode* root, vector<vector<int>> &res, int depth) {
        if (!root) return;
        if (res.size() <= depth) {
            vector<int> v;
            v.push_back(root->val);
            res.push_back(v);
        } else {
            res[depth].push_back(root->val);
        }
        if (root->left) dfs(root->left, res, depth+1);
        if (root->right) dfs(root->right, res, depth+1);
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res, 0);
        for(int i = 1; i < res.size(); i+=2) {
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
};
