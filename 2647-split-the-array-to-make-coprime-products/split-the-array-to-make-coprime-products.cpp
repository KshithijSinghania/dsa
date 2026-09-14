#define MAX 1000005
class Solution {
public:
    vector <int> getpfactor(int n){
        vector <int> res;
        for(int i=2;i<1000;i++){
            if(n%i==0){
                res.push_back(i);
                while(n%i==0) n/=i;
            }
        }
        if(n>1) res.push_back(n);
        return res;
    }
    int findValidSplit(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return -1;
        unordered_map <int,int> mpr;
        unordered_map <int,int> mpl;
        unordered_map <int,vector <int>> pfv;

        for(int i=0;i<n;i++){
            int val=nums[i];
            vector <int> pf=getpfactor(val);
            pfv[i]=pf;
            for(auto el:pf){
                mpr[el]=i;
                if(mpl.find(el)==mpl.end()) mpl[el]=i;
            }
        }

        int mx_go_right=0;
        for(int i=0;i<n;i++){
            vector <int> pf=pfv[i];
            for(auto el:pf){
                mx_go_right=max(mx_go_right,mpr[el]);
            }
            if(i+1>mx_go_right) break;
        }
        int mx_go_left=n;
        for(int i=n-1;i>=0;i--){
            vector <int> pf=pfv[i];
            for(auto el:pf){
                mx_go_left=min(mx_go_left,mpl[el]);
            }
            if(i-1<mx_go_left) break;
        }

        if(mx_go_left<=mx_go_right) return -1;

        return mx_go_right;
    }
};