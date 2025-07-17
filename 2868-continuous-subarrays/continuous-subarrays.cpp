class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        deque <int> minD,maxD;
        int l=0;
        int r=0;
        long long ans=0;
        for(;r<n;r++){
            while(minD.size() && nums[minD.back()]>=nums[r])minD.pop_back();
            while(maxD.size() && nums[maxD.back()]<=nums[r])maxD.pop_back();
            minD.push_back(r);
            maxD.push_back(r);
            while(nums[maxD.front()]-nums[minD.front()]>2){
                l++;
                if(minD.front()<l)minD.pop_front();
                if(maxD.front()<l)maxD.pop_front();
            }
            ans+=r-l+1;
        }
        return ans;
    }
};