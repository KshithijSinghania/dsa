class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int cp=0;
        int cn=0;
        vector <int> ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[2*cp]=nums[i];
                cp++;
            }
            else{
                ans[2*cn+1]=nums[i];
                cn++;
            }
        }
        return ans;   
    }
};