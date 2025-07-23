class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int n=nums.size();
        if(start==n)
        return {-1,-1};
        if(nums[start]!=target)
        return {-1,-1};
        int end=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        return {start,end-1};
    }
};