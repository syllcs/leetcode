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
 //when you have to use level traverse, just think whether it is possible to change it into bfs with some position infomation in the function.
class Solution {
protected:
    void dfs(TreeNode* root, int depth, int pos, vector<int>& min_v, vector<int>& max_v) {
        if (!root) return;
        if (min_v.size() <= depth) {
            min_v.push_back(pos);
            max_v.push_back(pos);
        } else {
            if (min_v[depth] > pos) min_v[depth] = pos;
            if (max_v[depth] < pos) max_v[depth] = pos;
        }
        dfs(root->left, depth+1, 2*pos, min_v, max_v);
        dfs(root->right, depth+1, 2*pos+1, min_v, max_v);
    }
    
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        vector<int> min_v, max_v;
        dfs(root, 0, 0, min_v, max_v);
        
        int res = 1;
        for (int i = 0; i < min_v.size(); i++) {
            int m = max_v[i] - min_v[i] + 1;
            res = max(res, m);
        }
        return res;
    }
};

