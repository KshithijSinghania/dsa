class Solution {
public:
    vector <vector <int>> dp;
    int solve(int r,int c){
        if(r==1 && c==1)
        return 1;
        if(r<=0 || c<=0)
        return 0;
        if(dp[r][c]!=-1)
        return dp[r][c];
        int left=solve(r,c-1);
        int up=solve(r-1,c);
        return dp[r][c]=left+up;
    }
    int uniquePaths(int m, int n) {
        vector <int> temp(n+1,-1);
        dp.resize(m+1,temp);
        return solve(m,n);
    }
};