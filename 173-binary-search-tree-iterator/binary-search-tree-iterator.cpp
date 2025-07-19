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
class BSTIterator {
public:
    int start;
    vector <int> v;
    BSTIterator(TreeNode* root) {
        inorder(root);
        start=0;
    }
    
    void inorder(TreeNode* root){
        if(root==NULL)
        return;
        if(root->left)
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }

    int next() {
        int num=v[start];
        start++;
        return num;
    }
    
    bool hasNext() {
        if(start==v.size())
        return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */