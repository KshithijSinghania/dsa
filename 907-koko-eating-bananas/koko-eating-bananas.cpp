class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int end=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            end=max(end,piles[i]);
        }
        int start=1;
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            int flag=true;
            int temp=h;
            for(int i=0;i<n;i++){
                // if(temp<=0){
                //     flag=false;
                //     break;
                // }
                temp=temp-((piles[i]+mid-1)/mid);
            }
            if(temp<0)
            flag=false;
            if(flag){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};