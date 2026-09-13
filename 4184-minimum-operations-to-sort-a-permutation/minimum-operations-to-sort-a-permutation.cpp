class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(((nums[(i+1)%n]+1)%n)==nums[i]) cnt1++;
            if(nums[(i+1)%n]==((nums[i]+1)%n)) cnt2++;
        }
        if(cnt1!=n && cnt2!=n) return -1;
        if(n==1) return 0;
        if(nums[0]==0 && nums.back()==n-1) return 0;
        if(cnt2==n) return min(n-nums[0],nums[0]+2);
        return min(nums.back()+1,n-nums.back()+1);
    }
};