class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        int low=0;
        int high=n-1;
        int idx=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(intervals[mid][0]<newInterval[0]){
            low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if(low==n)
        intervals.push_back(newInterval);
        else
        intervals.insert(intervals.begin()+low,newInterval);
        int l=intervals[0][0];
        int r=intervals[0][1];
        vector <vector <int>> ans;
        for(int i=1;i<n+1;i++){
            if(intervals[i][0]<=r){
                l=min(l,intervals[i][0]);
                r=max(r,intervals[i][1]);
            }
            else{
                ans.push_back({l,r});
                l=intervals[i][0];
                r=intervals[i][1];
            }
        }
        ans.push_back({l,r});
        return ans;
    }
};