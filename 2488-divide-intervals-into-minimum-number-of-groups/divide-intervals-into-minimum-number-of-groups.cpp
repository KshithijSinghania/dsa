class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector <int> start;
        vector <int> final;
        for(auto it:intervals){
            start.push_back(it[0]);
            final.push_back(it[1]);
        }
        sort(start.begin(),start.end());
        sort(final.begin(),final.end());
        int finalptr=0;
        int ans=0;
        for(auto st:start){
            if(st>final[finalptr])
            finalptr++;
            else{
                ans++;
            }
        }
        return ans;
    }
};