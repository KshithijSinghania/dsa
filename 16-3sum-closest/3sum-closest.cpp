class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int prevdiff=INT_MAX;
        int ans=0;
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int val=nums[i]+nums[j]+nums[k];
                int currdiff=abs(target-val);
                if(currdiff<prevdiff){
                    prevdiff=currdiff;
                    ans=val;
                }
                if(val==target)
                return val;
                else if(val>target)
                k--;
                else
                j++;
            }
        }
        return ans;
    }
};