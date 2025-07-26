class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map <vector <int>,vector <string>> m;
        for(auto it:strs){
            vector <int> chars(26,0);
            for(auto ch:it){
                chars[ch-'a']++;
            }
            m[chars].push_back(it);
        }
        vector <vector <string>> ans;
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
    }
};