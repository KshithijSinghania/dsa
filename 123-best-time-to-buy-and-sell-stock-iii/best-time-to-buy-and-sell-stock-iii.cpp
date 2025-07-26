class Solution {
public:
int n;
vector <vector <vector <int>>> dp;
    int solve(int idx,vector <int> &prices,int buy,int cap){
        if(idx==n || cap==0)
        return 0;
        if(dp[idx][buy][cap]!=-1)
        return dp[idx][buy][cap];
        if(buy){
            int take=-prices[idx]+solve(idx+1,prices,0,cap);
            int nottake=solve(idx+1,prices,1,cap);
            return dp[idx][buy][cap]=max(take,nottake);
        }
        int take=INT_MIN;
        if(cap)
        take=prices[idx]+solve(idx+1,prices,1,cap-1);
        int nottake=solve(idx+1,prices,0,cap);
        return dp[idx][buy][cap]=max(take,nottake);

    }
    int maxProfit(vector<int>& prices) {
       n=prices.size();
       dp.resize(n,vector <vector <int>>(2,vector <int>(3,-1)));
       return solve(0,prices,1,2);
    }
};