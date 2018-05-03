/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
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
    int depth(TreeNode* root, int &max_d) {
        if (!root) return 0;
        int left_d = depth(root->left, max_d);
        int right_d = depth(root->right, max_d);
        max_d = max(max_d, left_d+right_d+1);
        return 1 + max(left_d, right_d);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 1;
        depth(root, res);
        return res-1;
    }
};
