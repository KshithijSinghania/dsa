class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector <int> ans;
        for(auto maxi:queries){
            int temp=0;
            int val=0;
            for(auto it:nums){
                temp+=it;
                val++;
                if(temp>=maxi)
                break;
            }
            if(temp<=maxi)
            ans.push_back(val);
            else
            ans.push_back(val-1);
        }
        return ans;
    }
};