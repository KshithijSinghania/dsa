class Solution {
public:
    int build(int start,int end){
        if(start>=end)
        return 1;
        int ans=0;
        for(int i=start;i<=end;i++){
            int left=build(start,i-1);
            int right=build(i+1,end);
            ans+=(left*right);
        }
        return ans;
    }
    int numTrees(int n) {
        return build(1,n);
    }
};