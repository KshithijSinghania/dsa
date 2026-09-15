class Solution {
public:
    bool dfs(int i,int col,vector <vector <int>> &graph,vector <int> &color){
        color[i]=col;
        bool ans=true;
        for(auto it:graph[i]){
            if(color[it]==0){
                if(col==1)
                color[it]=2;
                else
                color[it]=1;
                if(!dfs(it,color[it],graph,color))
                return false;
            }
            else if(color[it]==col){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v, 0);
        queue<pair<int, int>> q;
        for (int i = 0; i < v; i++) {
            if (color[i] != 0)
                continue;
            if (!dfs(i,1,graph,color))
            return false;
        }
        return true;
    }
};