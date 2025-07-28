class Solution {
public:
    unordered_map <string,int> mpp;

    void dfs(string endWord,vector <string> temp,vector <vector <string>> &ans,string &beginWord){
        if (endWord == beginWord) {
            vector<string> path = temp;
            reverse(path.begin(), path.end());
            ans.push_back(path);
            return;
        }
        int step=mpp[endWord];
        for(int i=0;i<endWord.size();i++){
            string tempW=endWord;
            for(char ch='a';ch<='z';ch++){
                tempW[i]=ch;
                if(mpp.find(tempW)!=mpp.end() && mpp[tempW]==step-1){
                    cout<<tempW<<mpp[tempW]<<endl;
                    temp.push_back(tempW);
                    dfs(tempW,temp,ans,beginWord);
                    temp.pop_back();
                }
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map <string,int> m;
        int n=wordList.size();
        for(int i=0;i<n;i++){
            m[wordList[i]]++;
        }
        queue <pair<string,int>> q;
        q.push({beginWord,1});
        mpp[beginWord]=1;
        int flag=0;
        m.erase(beginWord);
        while(q.size()){
            string st=q.front().first;
            int dist=q.front().second;
            q.pop();
            if(st==endWord){
                flag=dist;
                //break;
            }
            for(int i=0;i<st.length();i++){
                string temp=st;
                for(int j=0;j<26;j++){
                    temp[i]=((char)(j+'a'));
                    if(m.find(temp)!=m.end()){
                        m.erase(temp);
                        mpp[temp]=dist+1;
                        q.push({temp,dist+1});
                    }
                }
            }
        }
        vector <vector <string>> ans;
        if(flag==0)
        return ans;
        cout<<flag;
        // for(auto it:mpp){
        //     cout<<it.first<<it.second<<endl;
        // }
        vector <string> temp;
        temp.push_back(endWord);
        dfs(endWord,temp,ans,beginWord);
        return ans;
    }
};