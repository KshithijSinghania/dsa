class Solution {
public:
    unordered_map <string,int> mpp;
    vector <vector <string>> ans;
    void dfs(string endWord,string &beginWord,vector <string> temp){
        if(beginWord==endWord){
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            reverse(temp.begin(),temp.end());
            return;
        }

        for(int i=0;i<endWord.size();i++){
            string t=endWord;
            for(char ch='a';ch<='z';ch++){
                t[i]=ch;
                if(mpp.find(t)!=mpp.end() && mpp[t]==mpp[endWord]-1){
                    temp.push_back(t);
                    dfs(t,beginWord,temp);
                    temp.pop_back();
                }
            }
        }

    }


    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        unordered_map <string,int> m;
        for(auto it:wordList){
            m[it]++;
        }
        queue <pair<string,int>> q;
        q.push({beginWord,1});
        mpp[beginWord]=1;
        bool flag=true;
        m.erase(beginWord);
        while(q.size()){
            string str=q.front().first;
            int dist=q.front().second;
            q.pop();
            if(str==endWord){
                flag=false;
                // break;
            }
            for(int i=0;i<str.size();i++){
                string temp=str;
                for(char ch='a';ch<='z';ch++){
                    temp[i]=ch;
                    if(m.find(temp)!=m.end()){
                        m.erase(temp);
                        q.push({temp,dist+1});
                        mpp[temp]=dist+1;
                    }
                }
            }
        }
        
        if(flag)
        return ans;
        vector <string> temp;
        temp.push_back(endWord);
        dfs(endWord,beginWord,temp);
        return ans;
    }
};