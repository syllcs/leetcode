/*
You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]
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
    vector<int> res;
public:
    void helper(TreeNode* node, int depth) {
        if (node == NULL) return;
        if (res.size() <= depth) res.push_back(node->val);
        else if (res[depth] < node->val) res[depth] = node->val;
        helper(node->left, depth + 1);
        helper(node->right, depth + 1);
        return;
    }
    vector<int> largestValues(TreeNode* root) {
        if (root == NULL) return res;
        helper(root, 0);
        return res;
        
    }
};
