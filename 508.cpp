/*
Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.
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
    map<int, int> m;
public:
    int treeSum(TreeNode* root) {
        if (root == NULL) return 0;
        map<int, int>::iterator it;
        int sum = root->val + treeSum(root->left) + treeSum(root->right);
        m[sum]++;
        return sum; 
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        treeSum(root);
        vector<int> res;
        int maxFreq = 0;
        for (auto i : m) {
            if (i.second > maxFreq) {
                res.clear();
                res.push_back(i.first);
                maxFreq = i.second;
            }
            else if (i.second == maxFreq) 
                res.push_back(i.first);
        }
        return res;
    }
};

