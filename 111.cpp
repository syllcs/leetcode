/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
*/
// as a easy level problem, it has a very low acceptance. 
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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        int min_l = INT_MAX;
        if (root->left) min_l = min(min_l, minDepth(root->left));
        if (root->right) min_l = min(min_l, minDepth(root->right));
        return min_l + 1;
    }
};
/*
// a very clever code that I saw on leetcode:
			int l = minDepth(root->left);
            int r = minDepth(root->right);
            if(l == 0)
                l = r;
            if(r == 0)
                r = l;
            return min(l,r) + 1;
