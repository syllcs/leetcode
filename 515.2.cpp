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
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        int num = 1;
        while(num != 0) {
            int largest;
            int new_num = 0;
            for (int i = 0; i < num; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(i == 0) largest = node->val;
                else largest = largest > (node->val) ? largest : (node->val);
                if (node->left != NULL) {
                    q.push(node->left);
                    new_num++;
                }
                if (node->right != NULL) {
                    q.push(node->right);
                    new_num++;
                }
            }
            num = new_num;
            res.push_back(largest);
        }
        return res;
    }
};
