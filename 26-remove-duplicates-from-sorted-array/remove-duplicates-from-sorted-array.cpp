class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map <int,int> m;
        vector <int> temp;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])==m.end()){
            m[nums[i]]++;
            temp.push_back(nums[i]);
            }
        }
        for(int i=0;i<temp.size();i++){
            nums[i]=temp[i];
        }
        return temp.size();
    }
};