class Solution {
public:
    int n;
    vector <int> dp;
    int solve(int idx,vector <int> &nums){
        if(idx>=n)
        return 0;
        if(dp[idx]!=-1)
        return dp[idx];
        int take=nums[idx]+solve(idx+2,nums);
        int nottake=solve(idx+1,nums);
        return dp[idx]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        n=nums.size();
        dp.resize(n,-1);
        return solve(0,nums);
    }
};