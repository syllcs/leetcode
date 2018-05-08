/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: ¡°The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).¡±

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

*/
//return as soon as you find both of the nodes are in this subtree and never change it again.
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
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q, bool &ep, bool &eq, bool &found, TreeNode* &lca) {
        ep = false;
        eq = false;
        if (!root) return;
        if (found) return;
        if (p == root) ep = true;
        if (q == root) eq = true;
        
        bool epl, eql;
        dfs(root->left, p, q, epl, eql, found, lca);
        if (found) return;
        if ((ep && eql) || (eq && epl)) {
            found = true;
            lca = root;
            return;
        }
        
        ep = ep || epl;
        eq = eq || eql;
        
        dfs(root->right, p, q, epl, eql, found, lca);
        if(found) return;
        if ((ep && eql) || (eq && epl)) {
            found = true;
            lca = root;
            return;
        }
        ep = ep || epl;
        eq = eq || eql;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *res;
        bool ep, eq, found = false;
        dfs(root, p, q, ep, eq, found, res);
        return res;
    }
};
