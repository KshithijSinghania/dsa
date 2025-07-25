class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector <int> temp;
        for(int i=0;i<n;i++){
            int idx=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
            if(idx==temp.size())
            temp.push_back(nums[i]);
            else{
                temp[idx]=nums[i];
            }
        }
        return temp.size();
    }
};