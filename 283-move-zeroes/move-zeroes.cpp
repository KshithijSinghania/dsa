class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero=0;
        for(int n_zero=0;n_zero<nums.size();n_zero++){
            if(nums[n_zero]!=0){
            nums[zero]=nums[n_zero];
            if(zero!=n_zero) nums[n_zero]=0;
            zero++;
            }
        }
    }
};