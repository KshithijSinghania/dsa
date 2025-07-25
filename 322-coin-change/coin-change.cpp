class Solution {
public:
vector <vector <int>> dp;
    int solve(int idx,int amount,vector <int> &coins){
        if(idx==0){
            if(amount%coins[idx]==0)
            return amount/coins[idx];
            else
            return 1e9;
        }
        if(dp[idx][amount]!=-1)
        return dp[idx][amount];
        int take=1e9;
        if(coins[idx]<=amount)
        take=1+solve(idx,amount-coins[idx],coins);
        int nottake=solve(idx-1,amount,coins);
        return dp[idx][amount]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector <int> temp(amount+1,-1);
        dp.resize(n,temp);
        // int val=solve(n-1,amount,coins);
        int tot=amount;
        for(int idx=0;idx<n;idx++){
            for(int amount=0;amount<=tot;amount++){
                if(idx==0){
                   if(amount%coins[idx]==0)
                    dp[idx][amount]=amount/coins[idx];
                    else
                    dp[idx][amount]=1e9;
                    continue;
                }
                int take=1e9;
                if(coins[idx]<=amount)
                take=1+dp[idx][amount-coins[idx]];
                int nottake=dp[idx-1][amount];
                dp[idx][amount]=min(take,nottake);
            }
        }
        int val=dp[n-1][tot];
        return val>=1e9?-1:val;
    }
};