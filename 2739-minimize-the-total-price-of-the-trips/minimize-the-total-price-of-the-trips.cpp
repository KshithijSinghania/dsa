class Solution {
public:
    bool process(int start,int end,int par,vector <int> &cnt,vector <vector <int>> &adj){
        if(start==end)
        return true;
        for(auto it:adj[start]){
            if(it!=par){
                if(process(it,end,start,cnt,adj)){
                    cnt[it]++;
                    return true;
                }
            }
        }
        return false;
    }
    
    int dfs(int node,int par,bool par_taken,vector <int> &cnt,vector <int> &price,vector <vector <int>> &adj,vector <vector <int>> &dp){
        if(dp[node][par_taken]!=-1)
        return dp[node][par_taken];
        int childs=0;
        for(auto it:adj[node]){
            if(it!=par)
            childs++;
        }
        if(childs==0){
            if(par_taken)
            return dp[node][par_taken]=cnt[node]*price[node];
            return dp[node][par_taken]=cnt[node]*(price[node]/2);
        }
        if(par_taken){
            int ans=cnt[node]*price[node];
            for(auto it:adj[node]){
                if(it!=par){
                    ans+=dfs(it,node,0,cnt,price,adj,dp);
                }
            }
            return dp[node][par_taken]=ans;
        }
        int ans1=cnt[node]*price[node];
        int ans2=cnt[node]*(price[node]/2);
        for(auto it:adj[node]){
            if(it!=par){
                ans1+=dfs(it,node,0,cnt,price,adj,dp);
                ans2+=dfs(it,node,1,cnt,price,adj,dp);
            }
        }
        return dp[node][par_taken]=min(ans1,ans2);
    }

    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector <vector <int>> dp(51,vector <int> (2,-1));
        vector <vector <int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);            
        } 
        vector <int> cnt(n,0);
        for(auto it:trips){
            int start=it[0];
            int end=it[1];
            if(process(start,end,-1,cnt,adj)){
                cnt[start]++;
            }
        }
        return dfs(0,-1,0,cnt,price,adj,dp);
    }
};