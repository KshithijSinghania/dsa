class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char,int> m;
        int l=0;
        int r=0;
        int ans=0;
        int n=s.length();
        while(r<n && l<n){
            int initial=m.size();
            m[s[r]]=1;
            int final=m.size();
            if(initial==final){
                m[s[l]]--;
                if(m[s[l]]==0)
                m.erase(s[l]);
                l++;
                continue;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};