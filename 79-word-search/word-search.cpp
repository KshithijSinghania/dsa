class Solution {
public:
int n;
int m;
int wordsize;
    bool dfs(int r,int c,int idx,vector <vector <int>> &vis,string &word,vector <vector <char>> &board){
        if(idx==wordsize)
        return true;
        vis[r][c]=1;
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr<n && nr>=0 && nc<m && nc>=0 && board[nr][nc]==word[idx] && vis[nr][nc]==0){
                if(dfs(nr,nc,idx+1,vis,word,board)){
                    return true;
                }
            }
        }
        vis[r][c]=0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        wordsize=word.size();
        vector <vector <int>> vis(n,vector <int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && dfs(i,j,1,vis,word,board)){
                    return true;
                }
            }
        }
        return false;
    }
};