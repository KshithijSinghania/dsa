class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        unordered_map <int,int> m1;
        unordered_map <int,int> m2;
        for(int i=0;i<n;i++){
            m1[A[i]]=i;
            m2[B[i]]=i;
        }
        vector <int> ans(n,0);
        for(int i=0;i<n;i++){
            int idx1=m1[A[i]];
            int idx2=m2[A[i]];
            ans[max(idx1,idx2)]++;
        }
        for(int i=1;i<n;i++){
            ans[i]=ans[i]+ans[i-1];
        }
        return ans;
    }
};