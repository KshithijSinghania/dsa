class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue <int> pq;
        for(int i=0;i<gifts.size();i++){
            pq.push(gifts[i]);
        }
        while(k>0){
            k--;
            int num=pq.top();
            pq.pop();
            num=((int)(floor(sqrt(num))));
            pq.push(num);
        }
        long long ans=0;
        while(pq.size()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};