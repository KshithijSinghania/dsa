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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q)
        return root;
        TreeNode* fromleft=lowestCommonAncestor(root->left,p,q);
        TreeNode* fromright=lowestCommonAncestor(root->right,p,q);
        if(fromleft && fromright)
        return root;
        return fromleft?fromleft:fromright;
    }
};