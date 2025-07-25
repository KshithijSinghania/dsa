class Solution {
public:
    vector <vector <int>> dp;
    int solve(int idx,int amount,vector <int> &coins){
        if(idx==0){
            if(amount==0)
            return 1;
            if(amount%coins[idx]==0)
            return 1;
            return 0;
        }
        if(dp[idx][amount]!=-1)
        return dp[idx][amount];
        int take=0;
        if(coins[idx]<=amount)
        take=solve(idx,amount-coins[idx],coins);
        int nottake=solve(idx-1,amount,coins);
        return dp[idx][amount]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector <int> temp(amount+1,-1);
        dp.resize(n,temp);
        return solve(n-1,amount,coins);
    }
};