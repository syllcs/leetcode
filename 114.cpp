/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
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
    void dfs(TreeNode* root, TreeNode* &node) {
        if (!root) return;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        node->left = NULL;
        node->right = root;
        node = node->right;
        dfs(left, node);
        dfs(right, node);
    }
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode* new_root = new TreeNode(0);
        dfs(root, new_root);
        
    }
};
