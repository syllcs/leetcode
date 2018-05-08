/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
    TreeNode* buildTree(TreeNode* root, int k) {
        if (!root) return NULL;
        TreeNode* new_root = new TreeNode(root->val + k);
        new_root->left = buildTree(root->left, k);
        new_root->right = buildTree(root->right, k);
        return new_root;
    }
    // I forgot to and & to vec, and it took me several minutes to find the mistake. This should never happend again!
    void n_tree(vector<vector<TreeNode*>> &vec, int n) {
        vector<TreeNode*> res;
        for (int i = 0; i < n; i++) {
            for (TreeNode* node_left : vec[i]) {
                for (TreeNode* node_right : vec[n-1-i]) {
                    TreeNode* new_node = new TreeNode(i+1);
                    new_node->left = buildTree(node_left, 0);
                    new_node->right = buildTree(node_right, i+1);
                    res.push_back(new_node);
                }
            }
        }
        vec.push_back(res);
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        
        vector<vector<TreeNode*>> vec;
        vector<TreeNode*> zero_node;
        if (n == 0) return zero_node;
        zero_node.push_back(NULL);
        vec.push_back(zero_node);
        for (int i = 1; i <=n; i++) {
            n_tree(vec, i);
        }
        return vec[n];
    }
};
