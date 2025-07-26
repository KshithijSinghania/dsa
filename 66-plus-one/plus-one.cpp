class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int val=(digits[n-1]+1);
        digits[n-1]=val%10;
        int fac=val/10;
        for(int i=n-2;i>=0;i--){
            int val=digits[i]+fac;
            digits[i]=(val)%10;
            fac=val/10;
        }
        if(fac==1)
        digits.insert(digits.begin(),1);
        return digits;
    }
};