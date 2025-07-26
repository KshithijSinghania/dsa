class Solution {
public:
int n;
vector <vector <int>> dp;
    int solve(int idx,int prev_idx,vector <int> &nums){
        if(idx==n)
        return 0;
        if(dp[idx][prev_idx+1]!=-1)
        return dp[idx][prev_idx+1];
        int take=0;
        if(prev_idx==-1 || nums[prev_idx]<nums[idx]){
            take=1+solve(idx+1,idx,nums);
        }
        int nottake=solve(idx+1,prev_idx,nums);
        return dp[idx][prev_idx+1]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        dp.resize(n,vector <int> (n+1,-1));
        return solve(0,-1,nums);
    }
};