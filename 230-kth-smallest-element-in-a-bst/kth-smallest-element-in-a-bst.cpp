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
    int kthSmallest(TreeNode* root, int k) {
        vector <int> v;
        queue <TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(q.size()){
            while(q.front()){
                v.push_back(q.front()->val);
                if(q.front()->left)
                q.push(q.front()->left);
                if(q.front()->right)
                q.push(q.front()->right);
                q.pop();
            }
            q.pop();
            if(q.size())
            q.push(NULL);
        }
        priority_queue <int> pq;
        for(auto it:v){
            if(pq.size()<k)
            pq.push(it);
            else{
                if(pq.top()>it){
                    pq.pop();
                    pq.push(it);
                }
            }
        }
        return pq.top();
    }
};