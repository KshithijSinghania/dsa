class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=INT_MAX;
        for(int i=0;i<strs.size();i++){
            int len=strs[i].length();
            n=min(n,len);
        }
        string ans="";
        for(int idx=0;idx<n;idx++){
            for(int i=1;i<strs.size();i++){
                if(strs[i][idx]!=strs[i-1][idx])
                return ans;
            }
            ans+=strs[0][idx];
        }
        return ans;
    }
};