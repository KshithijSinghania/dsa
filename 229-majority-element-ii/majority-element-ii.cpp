class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector <int> ans;

int n=nums.size();

int major=(n/3)+1;

int count1=0;
int count2=0;

int element1=INT_MIN;
int element2=INT_MIN;

for(int index=0;index<n;index++){
//if never saw element 1 and element2 is not equal to nums[index]
if(count1==0 && element2!=nums[index]){
count1++;
element1=nums[index];
}
else if(count2==0 && element1!=nums[index]){
count2++;
element2=nums[index];
}
else if(nums[index]==element1) count1++;
else if(nums[index]==element2) count2++;
else{
count1--;
count2--;
}
}

count1=0;
count2=0;

for(int index=0;index<n;index++){
if(nums[index]==element1) count1++;
if(nums[index]==element2) count2++;
}

if(count1>=major)
ans.push_back(element1);

if(count2>=major)
ans.push_back(element2);

return ans;

    }
};