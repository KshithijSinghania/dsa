class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int score=0;
        int idx=0;
        for(int i=0;i<divisors.size();i++){
            int temp=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]%divisors[i]==0)
                temp++;
            }
            if(score<temp){
            score=max(score,temp);
            idx=i;
            }
            else if(score==temp){
                if(divisors[idx]>divisors[i])
                idx=i;
            }
        }
        return divisors[idx];
    }
};