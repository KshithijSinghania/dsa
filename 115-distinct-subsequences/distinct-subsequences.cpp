class Solution {
public:
    vector <vector <int>> dp;
    int solve(int idx1,int idx2,string &s,string &t){
        if (idx2 < 0) return 1;
        if (idx1 < 0) return 0;
        if(dp[idx1][idx2]!=-1)
        return dp[idx1][idx2];
        int take=0;
        if(s[idx1]==t[idx2]){
            take=solve(idx1-1,idx2-1,s,t);
        }
        int nottake=solve(idx1-1,idx2,s,t);
        return dp[idx1][idx2]=take+nottake;
    }
    int numDistinct(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        vector <int> temp(n2,-1);
        dp.resize(n1,temp);
        return solve(n1-1,n2-1,s,t);
    }
};