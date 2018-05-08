/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
public:
    bool hasPathSum(TreeNode* root, int sum) {
        dfs(root, sum, 0);
        return res;
    }

private:
    bool res = false;
    void dfs(TreeNode* root, int sum, int cal_sum) {
        if (!root) return;
        if (res) return;
        cal_sum += root->val;
        if (!root->left && !root->right) {
            if (sum == cal_sum) res = true;
            return;
        }
        dfs(root->left, sum, cal_sum);
        dfs(root->right, sum, cal_sum);
    }
};
