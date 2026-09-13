class Solution {
public:
    vector <vector <int>> cost;
    int n;
    vector <vector <int>> dp;
    int solve(int idx,int d){
        if(idx==n && d==0) return 0;
        if(idx==n || d==0) return 1e5;
        if(dp[idx][d]!=-1) return dp[idx][d];
        int ans=1e5;
        int val=0;
        for(int j=idx;j<n;j++){
            ans=min(ans,cost[idx][j]+solve(j+1,d-1));
        }
        return dp[idx][d]=ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n=jobDifficulty.size();
        cost.resize(n,vector <int> (n));
        dp.resize(n,vector <int> (d+1,-1));
        for(int i=0;i<n;i++){
            int maxi=jobDifficulty[i];
            for(int j=i;j<n;j++){
                maxi=max(maxi,jobDifficulty[j]);
                cost[i][j]=maxi;
            }
        }
        for(auto it:cost){
            for(auto ij:it) cout<<ij<<" ";
            cout<<endl;
        }
        int ans=solve(0,d);
        return ans==1e5?-1:ans;
    }
};