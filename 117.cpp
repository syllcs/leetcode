/*
Given a binary tree

struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
Recursive approach is fine, implicit stack space does not count as extra space for this problem.
Example:

Given the following binary tree,

     1
   /  \
  2    3
 / \    \
4   5    7
After calling your function, the tree should look like:

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \    \
4-> 5 -> 7 -> NULL
*/
// level traverse, use a variable to record the begining of next layer.
// keep going until layer->next == NULL for each layer.

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode *layer, *next_layer = NULL;
        layer = root;
        while(layer) {
            while(layer) {
                if (layer->left) {
                    if (layer->right) layer->left->next = layer->right;
                    else layer->left->next = nextChildren(layer);
                    if (!next_layer) next_layer = layer->left;
                }
                if (layer->right) {
                    layer->right->next = nextChildren(layer);
                    if (!next_layer) next_layer = layer->right;
                }
                layer = layer->next;
            }
            layer = next_layer;
            next_layer = NULL;
        }
    }

private:
    TreeLinkNode* nextChildren(TreeLinkNode* node) {
        while (node->next) {
            node = node->next;
            if (node->left || node->right) {
                return node->left ? node->left : node->right;
            }
        }
        return NULL;
    }
/*
public:
    //wrong order, right part is not really when using it.
    TreeLinkNode* nextChildren(TreeLinkNode* node) {
        while (node->next) {
            node = node->next;
            if (node->left || node->right) {
                return node->left ? node->left : node->right;
            }
        }
        return NULL;
    }
    void connect(TreeLinkNode *root) {
        if (!root) return;
        if (root->left) {
            if (root->right) 
                root->left->next = root->right;
            else root->left->next = nextChildren(root);
        }
        if (root->right) {
            root->right->next = nextChildren(root);
        }
        connect(root->left);
        connect(root->right);
    }
    */
};
