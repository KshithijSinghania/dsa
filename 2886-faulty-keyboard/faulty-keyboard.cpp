class Solution {
public:
    string finalString(string s) {
        string ans="";
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='i'){
                int size=ans.size();
                reverse(ans.begin(),ans.begin()+size);
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};