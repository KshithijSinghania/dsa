class Solution {
public:
     vector <vector <int>> dp;
    int solve(int r,int c,vector <vector <int>> &obstacleGrid){
        if(r==-1 || c==-1)
        return 0;
        if(obstacleGrid[r][c]==1)
        return 0;
        if(r==0 && c==0)
        return 1;
        if(dp[r][c]!=-1)
        return dp[r][c];
        int left=solve(r-1,c,obstacleGrid);
        int up=solve(r,c-1,obstacleGrid);
        return dp[r][c]=left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector <int> temp(m,-1);
        dp.resize(n,temp);
        return solve(n-1,m-1,obstacleGrid);
    }
};