/*
Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:
Input: 
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
Example 2:
Input: 
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.
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
    void bfs(TreeNode* node, int &min_num, int root_val) {
        if (!node) return;
        if (node->val != root_val) 
            if (min_num == -1 || min_num > node->val)
                min_num = node->val;
        if (min_num != -1 && node->val > min_num) return;
        bfs(node->left, min_num, root_val);
        if (min_num != -1 && node->val > min_num) return;
        bfs(node->right, min_num, root_val);
        
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        int min_num = -1;
        bfs(root, min_num, root->val);
        return min_num;
        /*
        //level order traverse, wrong answer.
        if (!root) return -1;
        if (!(root->left)) return -1;
        int root_val = root->val;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        int num = 2;
        while(num != 0) {
            int min_num = -1;
            int new_num = 0;
            for(int i = 0; i < num; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (min_num == -1 && node->val == root_val) {
                    if(node->left) {q.push(node->left); new_num++;}
                    if(node->right) {q.push(node->right); new_num++;}
                }
                else if(min_num == -1 && node->val != root->val) 
                    min_num = node->val;
                else if(node->val != root->val && node->val < min_num) min_num = node->val;
            }
            if(min_num != -1) return min_num;
            num = new_num;
        }
        return -1;
        */
    }
};
