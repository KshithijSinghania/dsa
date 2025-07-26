class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector <int> dp(n,1);
        vector <int> hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<1+dp[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                    hash[i]=j;
                    }
                }
            }
        }
        vector <int> ans;
        int maxidx=max_element(dp.begin(),dp.end())-dp.begin();
        while(maxidx!=hash[maxidx]){
            ans.push_back(nums[maxidx]);
            maxidx=hash[maxidx];
        }
        ans.push_back(nums[maxidx]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};