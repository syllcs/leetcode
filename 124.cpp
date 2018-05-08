/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
*/
// an easy dp problem.
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
    int singlepath(TreeNode* root, int &max_path) {
        if (!root) return 0;
        int left = max(singlepath(root->left, max_path), 0);
        int right = max(singlepath(root->right, max_path), 0);
        max_path = max(max_path, left + right + root->val);
        return max(root->val + left, root->val + right);
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int max_path = INT_MIN;
        singlepath(root, max_path);
        return max_path;
    }
};
