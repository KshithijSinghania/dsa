class Solution {
public:
    void dfs(int i,vector <vector <int>> &adj,vector <int> &vis){
        vis[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector <vector <int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(isConnected[i][j]){
                        adj[i].push_back(j);
                    }
                }
            }
        }
        int ans=0;
        vector <int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                queue <int> q;
                q.push(i);
                vis[i]=1;
                while(q.size()){
                    int node=q.front();
                    q.pop();
                    for(auto it:adj[node]){
                        if(!vis[it]){
                            vis[it]=1;
                            q.push(it);
                        }
                    }
                }
            }
        }
        return ans;
    }
};