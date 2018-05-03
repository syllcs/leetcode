/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> layer;
        queue<TreeNode*> q;
        if (!root) return res;
        
        q.push(root);
        int num = 1, new_num = 0;
        while (num != 0) {
            for(int i = 0; i < num; i++) {
                TreeNode* node = q.front();
                q.pop();
                layer.push_back(node->val);
                if (node->left) {
                    new_num++;
                    q.push(node->left);
                }
                if (node->right) {
                    new_num++;
                    q.push(node->right);
                }
            }
            res.push_back(layer);
            layer.clear();
            num = new_num;
            new_num = 0;
        }
        return res;
    }
}; 
