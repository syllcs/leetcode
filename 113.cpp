/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
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
    void dfs(TreeNode* root, int& cal_sum, int sum, vector<int> &v, vector<vector<int>> &res) {
        if (!root) return;
        cal_sum += root->val;
        v.push_back(root->val);
        if ((!root->left) && (!root->right)) {
            if (cal_sum == sum) {
                res.push_back(v);
            }
        } else {
            dfs(root->left, cal_sum, sum, v, res);
            dfs(root->right, cal_sum, sum, v, res);
        }
        cal_sum -= root->val;
        v.erase(v.end() - 1);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        int cal_sum = 0;
        vector<int> v;
        vector<vector<int>> res;
        dfs(root, cal_sum, sum, v, res);
        return res;
    }
}; 
