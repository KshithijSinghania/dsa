class Solution {
public:
int n;
int totsum=0;
vector<vector <int>> dp;
    bool solve(int idx,int sum,vector <int> &nums){
        if(idx==n){
            if(sum==(totsum/2))
            return true;
            else
            return false;
        }
        if(dp[idx][sum]!=-1)
        return dp[idx][sum];
        int take=solve(idx+1,sum+nums[idx],nums);
        int nottake=solve(idx+1,sum,nums);
        return dp[idx][sum]=take|nottake;
    }
    bool canPartition(vector<int>& nums) {
        n=nums.size();
        for(auto it:nums)
        totsum+=it;
        if(totsum%2==1)
        return false;
        vector <int> temp(20001,-1);
        dp.resize(n,temp);
        return solve(0,0,nums);
    }
};