/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ¡Ü k ¡Ü BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
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
    int nodeNum(TreeNode* root) {
        if (!root) return 0;
        return nodeNum(root->left) + nodeNum(root->right) + 1;
    }
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* node;
        int rootorder;
        rootorder = nodeNum(root->left);
        if (rootorder == k-1) return root->val;
        if (rootorder > k-1) return kthSmallest(root->left, k);
        return kthSmallest(root->right, k - rootorder - 1);
        
    }
};
