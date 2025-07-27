class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)
        return n;
        int pin=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1] && pin==0){
                pin=1;
            }
            else if(nums[i]==nums[i-1] && pin==1){
                nums.erase(nums.begin()+i);
                i--;
            }
            else{
                pin=0;
            }
        }
        return nums.size();
    }
};