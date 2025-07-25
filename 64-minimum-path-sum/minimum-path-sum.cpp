class Solution {
public:
vector <vector <int>> dp;
    int pathsum(int r,int c,vector <vector <int>> &grid){
        if(r<0 || c<0)
        return 1e9;
        if(r==0 && c==0)
        return grid[r][c];
        if(dp[r][c]!=-1)
        return dp[r][c];
        int leftsum=grid[r][c]+pathsum(r,c-1,grid);
        int upsum=grid[r][c]+pathsum(r-1,c,grid);
        return dp[r][c]=min(leftsum,upsum);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector <int> temp(m,-1);
        dp.resize(n,temp);
        return pathsum(n-1,m-1,grid);
    }
};