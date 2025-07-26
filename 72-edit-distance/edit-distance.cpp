class Solution {
public:
    vector <vector <int>> dp;
    int solve(int idx1,int idx2,string &word1,string &word2){
        if(idx1<0 && idx2<0)
        return 0;
        if(idx2<0)
        return idx1+1;
        if(idx1<0)
        return idx2+1;
        if(dp[idx1][idx2]!=-1)
        return dp[idx1][idx2];
        if(word1[idx1]==word2[idx2]){
            return dp[idx1][idx2]=solve(idx1-1,idx2-1,word1,word2);
        }
        int val1=1+solve(idx1-1,idx2-1,word1,word2);
        int val2=1+solve(idx1-1,idx2,word1,word2);
        int val3=1+solve(idx1,idx2-1,word1,word2);
        return dp[idx1][idx2]=min(min(val1,val2),val3);
    }
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector <int> temp(n2,-1);
        dp.resize(n1,temp);
        return solve(n1-1,n2-1,word1,word2);
    }
};