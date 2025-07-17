class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int n = nums.size();
        for (int num : nums) {
            maxi = max(maxi, num);
        }
        long long ans=0;
        int left=0;
        int right=0;
        int curr=0;
        for(;right<n;right++){
            if(nums[right]==maxi)
            curr++;
            if(curr==k){
                while(curr==k){
                    if(nums[left]==maxi){
                        curr--;
                    }
                    left++;
                }
            }
            ans+=left;
        }
        return ans;
    }
};
