/*
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (!root) return res;
        vector<TreeNode*> s1, s2;
        s1.push_back(root);
        while (!s1.empty()) {
            int num = 0;
            double sum = 0.0;
            for (TreeNode* node : s1) {
                num++;
                sum += node->val;
                if (node->left) s2.push_back(node->left);
                if (node->right) s2.push_back(node->right);
            }
            res.push_back(sum/num);
            s1 = s2;
            s2.clear();
        }
        return res;
    }
};
