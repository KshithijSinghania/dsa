class Solution {
public:
    bool isValidSquare(int r,int c,vector <vector <char>> &grid){
        unordered_set<char> st;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int nr=r+i;
                int nc=c+j;
                if(st.find(grid[nr][nc])!=st.end())
                return false;
                if(grid[nr][nc]!='.')
                st.insert(grid[nr][nc]);
            }
        }
        return true;
    }

    bool isValidRow(int r,vector <vector <char>> &grid){
        unordered_set<char> st;
        for(int j=0;j<9;j++){
            if(st.find(grid[r][j])!=st.end())
            return false;
            if(grid[r][j]!='.')
            st.insert(grid[r][j]);
        }
        return true;
    }

    bool isValidCol(int c,vector <vector <char>> &grid){
        unordered_set<char> st;
        for(int i=0;i<9;i++){
            if(st.find(grid[i][c])!=st.end())
            return false;
            if(grid[i][c]!='.')
            st.insert(grid[i][c]);
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& grid) {
        if(!isValidSquare(0,0,grid))
        return false;
        if(!isValidSquare(0,3,grid))
        return false;
        if(!isValidSquare(0,6,grid))
        return false;
        if(!isValidSquare(3,0,grid))
        return false;
        if(!isValidSquare(3,3,grid))
        return false;
        if(!isValidSquare(3,6,grid))
        return false;
        if(!isValidSquare(6,0,grid))
        return false;
        if(!isValidSquare(6,3,grid))
        return false;
        if(!isValidSquare(6,6,grid))
        return false;
        for(int i=0;i<9;i++){
            if(!isValidRow(i,grid))
            return false;
            if(!isValidCol(i,grid))
            return false;
        }
        return true;
    }
};