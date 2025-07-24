class Solution {
public:
    int solve(vector<int>& nums, int k){
        int n=nums.size();
        map <int,int> m;
        int l=0;
        int r=0;
        int ans=0;
        while(r<n){
            m[nums[r]]++;
            if(m.size()>k){
                while(m.size()>k){
                    m[nums[l]]--;
                    if(m[nums[l]]==0)
                    m.erase(nums[l]);
                    l++;
                }
            }
            ans+=r-l+1;
            r++;
        }
        return ans;  
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);         
    }

};