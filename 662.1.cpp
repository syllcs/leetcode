/*
Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:
Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:
Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:
Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:
Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).
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
 // a really really bad solution that I wrote. 
 // the complexity is O(n), O(n), which is fine. but the approach is just too trivial.
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        int max_num = 1;
        vector<TreeNode*> layer;
        layer.push_back(root);
        
        bool exist_node = true;
        while (exist_node) {
            bool new_exist = false;
            vector<TreeNode*> next_layer;
            for(TreeNode* node : layer) {
                if (!node) {
                    next_layer.push_back(NULL);
                    next_layer.push_back(NULL);
                } else {
                    if(node->left) {next_layer.push_back(node->left); new_exist = true;}
                    else next_layer.push_back(NULL);
                    if(node->right) {next_layer.push_back(node->right); new_exist = true;}
                    else next_layer.push_back(NULL);
                }
            }
            if(new_exist) {
                int begin = -1;
                int end = -1;
                int count = 0;
                for (TreeNode* node : next_layer) {
                    if (node) {
                        if (begin == -1) {begin = count; end = count;}
                        else end = count;
                    }
                    count++;
                }
                layer.clear();
                for (int i = begin; i <= end; i++) {
                    layer.push_back(next_layer[i]);
                }
                max_num = max_num > end - begin + 1 ? max_num : end - begin + 1;
            }
            next_layer.clear();
            exist_node = new_exist;
        }
        return max_num;
    }
};
