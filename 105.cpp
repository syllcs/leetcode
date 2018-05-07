/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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
    using it=vector<int>::iterator;
    TreeNode* do_buildTree(vector<int>& preorder, vector<int>& inorder, it prebeg, it preend, it inbeg, it inend) {
        //if ((prebeg > preend) || (prebeg == preorder.end())) return NULL;
        if (prebeg > preend) return NULL;
        TreeNode* node = new TreeNode(*prebeg);
        it pos_node = find(inbeg, inend + 1, *prebeg);
        
        it l_in_beg = inbeg;
        it l_in_end = pos_node - 1;
        it r_in_beg = pos_node + 1;
        it r_in_end = inend;
        
        it l_pre_beg = prebeg + 1;
        it l_pre_end = l_pre_beg + (l_in_end - inbeg);
        it r_pre_beg = l_pre_end + 1;
        it r_pre_end = preend;
        
        node->left = do_buildTree(preorder, inorder, l_pre_beg, l_pre_end, l_in_beg, l_in_end);
        node->right = do_buildTree(preorder, inorder, r_pre_beg, r_pre_end, r_in_beg, r_in_end);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return NULL;
        return do_buildTree(preorder, inorder, preorder.begin(), preorder.end() - 1, inorder.begin(), inorder.end() - 1);
    }
};
