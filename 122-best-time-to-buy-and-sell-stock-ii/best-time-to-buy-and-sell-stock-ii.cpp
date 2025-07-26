class Solution {
public:
int n;
vector <vector <int>> dp;
    int solve(int idx,int buy,vector <int> &prices){
        if(idx==n-1){
            if(buy==0)
            return prices[idx];
            return 0;
        }
        if(dp[idx][buy]!=-1)
        return dp[idx][buy];
        if(buy){
            int take=-prices[idx]+solve(idx+1,0,prices);
            int nottake=solve(idx+1,1,prices);
            return dp[idx][buy]=max(take,nottake);
        }
        int take=prices[idx]+solve(idx+1,1,prices);
        int nottake=solve(idx+1,0,prices);
        return dp[idx][buy]=max(take,nottake);
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        vector <int> temp(2,-1);
        dp.resize(n,temp);
        return solve(0,1,prices);
    }
};