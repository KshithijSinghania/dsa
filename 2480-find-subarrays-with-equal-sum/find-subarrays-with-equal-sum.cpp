class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map <long long,int> m;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            long long sum=nums[i]+nums[i+1];
            if(m.find(sum)!=m.end()){
                return true;
            }
            m[sum]++;
        }
        return false;
    }
};