class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
        return 0;
        unordered_set <int> m;
        for(auto it:nums){
            m.insert(it);
        }
        int ans=0;
        for(auto it:m){
            if(m.find(it-1)==m.end()){
                int count=0;
                int val=it;
                while(m.find(val)!=m.end()){
                    val++;
                    count++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};