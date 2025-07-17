
class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans(n , 0);
        int sum=0;
        for(int i=0; i<n; i++){
            ans[i] = ans[i/2] + (i&1);
            if(ans[i]==k){
                sum += nums[i];
            }
        }
        return sum;
    }
};
