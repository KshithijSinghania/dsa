class Solution {
public:
    int n;
    vector <int> dp;
    bool isPalin(int i,int j,string &s){
        while(i<=j){
            if(s[i]!=s[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i,string &s){
        if(i==n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int mini=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalin(i,j,s))
            mini=min(mini,1+solve(j+1,s));
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        n=s.length();
        dp.resize(n,-1);
        return solve(0,s)-1;
    }
};