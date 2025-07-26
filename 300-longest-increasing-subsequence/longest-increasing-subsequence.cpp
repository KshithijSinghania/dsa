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
        dp.resize(n+1,vector <int> (n+1,0));
        for(int idx=n-1;idx>=0;idx--){
            for(int prev_idx=n-1;prev_idx>=-1;prev_idx--){
                int take=0;
                if(prev_idx==-1 || nums[prev_idx]<nums[idx]){
                take=1+dp[idx+1][idx+1];
                }
                int nottake=dp[idx+1][prev_idx+1];
                dp[idx][prev_idx+1]=max(take,nottake);
            }
        }
        return dp[0][0];


        //return solve(0,-1,nums);
    }
};