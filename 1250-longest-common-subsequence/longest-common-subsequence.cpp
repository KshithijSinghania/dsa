class Solution {
public:
    vector <vector <int>> dp;
    int solve(int idx1,int idx2,string &text1,string &text2){
        if(idx1<0 || idx2<0)
        return 0;
        if(dp[idx1][idx2]!=-1)
        return dp[idx1][idx2];
        if(text1[idx1]==text2[idx2])
        return dp[idx1][idx2]=1+solve(idx1-1,idx2-1,text1,text2);
        int case1=solve(idx1-1,idx2,text1,text2);
        int case2=solve(idx1,idx2-1,text1,text2);
        return dp[idx1][idx2]=max(case1,case2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector <int> temp(n2+1,0);
        dp.resize(n1+1,temp);
        // return solve(n1-1,n2-1,text1,text2);
        for(int idx1=1;idx1<=n1;idx1++){
            for(int idx2=1;idx2<=n2;idx2++){
                if(text1[idx1-1]==text2[idx2-1]){
                dp[idx1][idx2]=1+dp[idx1-1][idx2-1];
                continue;
                }
                int case1=dp[idx1-1][idx2];
                int case2=dp[idx1][idx2-1];
                dp[idx1][idx2]=max(case1,case2);
            }
        }
        return dp[n1][n2];
    }
};