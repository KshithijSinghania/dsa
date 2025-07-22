class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        //vector <int> nge(n,-1);
        stack<int> st;
        unordered_map <int,int> m;
        for(int i=n-1;i>=0;i--){
            while(st.size()){
                if(st.top()<=nums2[i])
                st.pop();
                else{
                m[nums2[i]]=st.top();
                break;
                }
            }
            st.push(nums2[i]);
        }
        vector <int> ans;
        n=nums1.size();
        for(int i=0;i<n;i++){
            if(m.find(nums1[i])==m.end())
            ans.push_back(-1);
            else
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};