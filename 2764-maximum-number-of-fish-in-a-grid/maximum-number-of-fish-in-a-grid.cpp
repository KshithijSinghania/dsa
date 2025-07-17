class Solution {
public:
    int ans=INT_MIN;
    int val=0;
    void dfs(int r,int c,vector <vector <int>> &vis,vector <vector <int>> &grid,int n,int m){
        vis[r][c]=1;
        val+=grid[r][c];
        ans=max(ans,val);
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr<n && nr>=0 && nc<m && nc>=0 && grid[nr][nc]!=0 && vis[nr][nc]==0){
                dfs(nr,nc,vis,grid,n,m);
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector <vector <int>> vis(n,vector <int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0 && vis[i][j]==0){
                    val=0;
                    dfs(i,j,vis,grid,n,m);
                }
            }
        } 
        return ans==INT_MIN?0:ans;   
    }
};