/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* create(int start,int end,vector<int>& preorder){
        if(start>end)
        return NULL;
        TreeNode* root=new TreeNode(preorder[start]);
        int curr_val=root->val;
        int left_max=start+1;
        for(;left_max<=end;left_max++){
            if(preorder[left_max]>curr_val)
            break;
        }
        root->left=create(start+1,left_max-1,preorder);
        root->right=create(left_max,end,preorder); 
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return create(0,preorder.size()-1,preorder);
    }
};