/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?
*/
//be careful about the special case: two reversed node are adjacent.
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
    TreeNode *first = NULL, *second = NULL;
    TreeNode* last_node = new TreeNode(INT_MIN);
    bool found_s = false;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (root->val < last_node->val) {
            if (!first) {
                first = last_node;
                second = root;
            } else if (!found_s) {
                second = root;
                found_s = true;
            } else return;
        }
        last_node = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp;
        temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};
