class Solution {
public:
    vector<vector<int>> generate(int n) {
        	//handling edge cases
vector <vector <int>> ans;
	
ans.push_back({1});
if(n==1){
return ans;
}

ans.push_back({1,1});
if(n==2){
return ans;
}

//for rest of the cases
for(int level=2;level<n;level++){
vector <int> temporary;
temporary.push_back(1);
for(int index=1;index<level;index++){
temporary.push_back(ans[level-1][index-1]+ans[level-1][index]);
}
temporary.push_back(1);
ans.push_back(temporary);
}

return ans;

    }
};