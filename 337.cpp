/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
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
    int rob(TreeNode* root) {
        if (!root) return 0;
        rob(root->left);
        rob(root->right);
        int include_root = 0;
        int exclude_root = 0;
        
        include_root += root->val;
        if (root->left) {
            exclude_root += root->left->val;
            if (root->left->left) include_root += root->left->left->val;
            if (root->left->right) include_root += root->left->right->val;
        }
        if (root->right) {
            exclude_root += root->right->val;
            if (root->right->left) include_root += root->right->left->val;
            if (root->right->right) include_root += root->right->right->val;
        }
        root->val = max(include_root, exclude_root);
        return root->val;
    }
    /*
    //exponential complexity
    int rob(TreeNode* root) {
        if (!root) return 0;
        int left_ex = 0, right_ex = 0;
        if (root->left) 
            left_ex = rob(root->left->left) + rob(root->left->right);
        if (root->right)
            right_ex = rob(root->right->left) + rob(root->right->right);
        int left_in = rob(root->left);
        int right_in = rob(root->right);
        return max(left_ex + right_ex + root->val, left_in + right_in);
    }
    */
    /* a typical wrong answer!
    void oddEven(TreeNode* root, int &odd, int &even, int depth) {
        if (!root) return;
        if (depth % 2 == 0) even += root->val;
        else odd += root->val;
        oddEven(root->left, odd, even, depth + 1);
        oddEven(root->right, odd, even, depth + 1);
    }
    int rob(TreeNode* root) {
        int odd = 0, even = 0;
        oddEven(root, odd, even, 0);
        return max(odd, even);
    }
    */
};
