class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue <pair <int,int>> q;
        int n=grid.size();
        q.push({0,0});
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
        return -1;
        int dr[]={0,1,0,-1,1,1,-1,-1};
        int dc[]={1,0,-1,0,1,-1,1,-1};
        vector <vector <int>> steps(n,vector <int> (n,1e9));
        steps[0][0]=1;
        while(q.size()){
            int r=q.front().first;
            int c=q.front().second;
            int step=steps[r][c];
            q.pop();
            if(r==n-1 && c==n-1)
            return step;
            for(int i=0;i<8;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr<n && nc<n && nr>=0 && nc>=0 && grid[nr][nc]==0 && steps[nr][nc]>1+steps[r][c]){
                    steps[nr][nc]=1+steps[r][c];
                    q.push({nr,nc});
                }
            }
        }
        return -1;
    }
};