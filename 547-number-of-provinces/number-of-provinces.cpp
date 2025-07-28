class Disjoint{
    public:
    vector <int> parent;
    vector <int> rank;
    Disjoint(int n){
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        rank.resize(n,1);
    }
    int findUPar(int i){
        if(parent[i]==i)
        return i;
        return parent[i]=findUPar(parent[i]);
    }

    void UnionByRank(int u,int v){
        int uu=findUPar(u);
        int uv=findUPar(v);
        if(uu==uv)
        return;
        int ru=rank[u];
        int rv=rank[v];
        if(ru<rv){
            parent[uu]=uv;
        }
        else if(rv<ru){
            parent[uv]=uu;
        }
        else{
            parent[uu]=uv;
            rank[uv]++;
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        // vector <vector <int>> adj(n);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(i!=j){
        //             if(isConnected[i][j]){
        //                 adj[i].push_back(j);
        //             }
        //         }
        //     }
        // }
        vector <pair <int,int>> edges;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(isConnected[i][j]){
                        edges.push_back({i,j});
                    }
                }
            }
        }
        Disjoint ds(n);
        for(auto it:edges){
            int u=it.first;
            int v=it.second;
            ds.UnionByRank(u,v);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)
            ans++;
        }
        
        return ans;
    }
};