/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <--- 
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        int num = 1, new_num = 0;
        while (num != 0) {
            for (int i = 0; i < num; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (i == num - 1) res.push_back(node->val);
                if (node->left) {
                    new_num++;
                    q.push(node->left);
                }
                if (node->right) {
                    new_num++;
                    q.push(node->right);
                }
            }
            num = new_num;
            new_num = 0;
        }
        return res;
    }
};
