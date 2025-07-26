class Solution {
public:
    int solve(int n){
        if(n<=0)
        return 1;
        return n*solve(n-1);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector <int>> ans;
        int n=nums.size();
        int fact=solve(n);
        for(int i=0;i<fact;i++){
            ans.push_back(nums);
            next_permutation(nums.begin(),nums.end());
        }
        return ans;
    }
};