/*
Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6
*/
//when when know the depth of the right sub tree, the number of a subtree can be calculated.
// time complexity O(log(n)*log(n));
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
    int countNodes(TreeNode* root) {
        int h = left_deep(root);
        int current_h = 1;
        int res = 0;
        while (root) {
            if (h == current_h + left_deep(root->right)) {
                res += pow(2, h - current_h);
                root = root->right;
            } else {
                res += pow(2, h - current_h - 1);
                root = root->left;
            }
            current_h++;
        }
        return res;
    }

private:
    int left_deep(TreeNode* root) {
        int count = 0;
        while (root) {
            count++;
            root = root->left;
        }
        return count;
    }
    /*
    // time limit exceeded
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int res = 1;
        res += countNodes(root->left);
        res += countNodes(root->right);
        return res;
    }
    */
};
