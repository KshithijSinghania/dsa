class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i]=nums[i]+nums[i-1];
        }
        map <int,int> m;
        int ans=0;
        for(int i=0;i<n;i++){
            int left=nums[i]-k;
            if(m.find(left)!=m.end()){
                ans+=m[left];
            }
            if(nums[i]==k)
            ans++;
            m[nums[i]]++;
        }
        return ans;
    }
};