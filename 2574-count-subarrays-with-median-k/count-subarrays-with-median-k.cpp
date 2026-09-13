class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        unordered_map <int,int> mp;
        int kid=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==k){
                kid=i;
                break;
            }
        }
        int d1=0;
        mp[d1]++;
        for(int i=kid+1;i<n;i++){
            if(nums[i]>k) d1++;
            else d1--;
            mp[d1]++;
        }
        int d2=0;
        int ans=0;
        ans+=(mp[1-d2]+mp[-1*d2]);
        for(int i=kid-1;i>=0;i--){
            if(nums[i]>k) d2++;
            else d2--;
            ans+=(mp[1-d2]+mp[-1*d2]);
        }
        return ans;
    }
};