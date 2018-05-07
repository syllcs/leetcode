/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
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
    using it = vector<int>::iterator;
    TreeNode* do_buildTree(it inb, it ine, it postb, it poste) {
        if (inb > ine) return NULL;
        TreeNode* node = new TreeNode(*poste);
        it pos = find(inb, ine, *poste);
        
        it l_in_beg = inb;
        it l_in_end = pos - 1;
        it r_in_beg = pos + 1;
        it r_in_end = ine;
        
        it l_post_beg = postb;
        it l_post_end = postb + (l_in_end - l_in_beg);
        it r_post_beg = l_post_end + 1;
        it r_post_end = poste - 1;
        
        node->left = do_buildTree(l_in_beg, l_in_end, l_post_beg, l_post_end);
        node->right = do_buildTree(r_in_beg, r_in_end, r_post_beg, r_post_end);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty()) return NULL;
        return do_buildTree(inorder.begin(), inorder.end() - 1, postorder.begin(), postorder.end() - 1);
    }
};
