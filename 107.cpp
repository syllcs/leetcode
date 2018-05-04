/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
    void dfs(TreeNode* node, int depth, vector<vector<int>> &res) {
        if (!node) return;
        if (res.size() <= depth) {
            vector<int> v;
            v.push_back(node->val);
            res.push_back(v);
        }
        else {
            res[depth].push_back(node->val);
        }
        dfs(node->left, depth+1, res);
        dfs(node->right, depth+1, res);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        dfs(root, 0, res);
        reverse(res.begin(), res.end());
        return res;
    }
};
