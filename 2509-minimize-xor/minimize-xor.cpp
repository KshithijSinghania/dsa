class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int numbits=0;
        for(int i=0;i<32;i++){
            if((num2|1<<i)==num2)
            numbits++;
        }
        int ans=0;
        int i=31;
        while(numbits>0 && i>=0){
            if((num1|1<<i)==num1){
                ans=ans|(1<<i);
                numbits--;
            }
            i--;
        }
        i=0;
        while(numbits>0 && i<32){
            if((ans|1<<i)!=ans){
                ans=ans|(1<<i);
                numbits--;
            }
            i++;
        }
        return ans;
    }
};