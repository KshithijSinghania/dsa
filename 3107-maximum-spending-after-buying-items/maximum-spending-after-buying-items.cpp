using pi = pair<int, int>;
class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        
        priority_queue <pi,vector <pi>,greater <pi>> pq;
        int n=values.size();
        int m=values[0].size();
        for(int i=0;i<n;i++){
            reverse(values[i].begin(),values[i].end());
        }
    
            for(int i=0;i<n;i++){
                pq.push({values[i][0],i});
            }
        
        vector <int> idx(n,0);
        long long timer=1;
        long long ans=0;
        while(pq.size()){
            pi top=pq.top();
            int val=top.first;
            int ind=top.second;
            pq.pop();
            ans+=(val*timer*1LL);
            timer++;
            idx[ind]++;
            if(idx[ind]<m){
                pq.push({values[ind][idx[ind]],ind});
            }
        }
        return ans;
    }
};