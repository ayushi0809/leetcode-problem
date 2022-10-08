class Solution {
public:
    unordered_map<string,int>m;
    vector<vector<string>>ans;
    void dfs(string endword,vector<string>v,int level,string beginword){
        if(endword==beginword){
            v.push_back(endword);
            reverse(v.begin(),v.end());
            ans.push_back(v);
            return;
        }
         v.push_back(endword);
        for(int i =0; i<endword.size();i++){
            char o = endword[i];
            for(char ch = 'a'; ch<='z';ch++){
                endword[i] = ch;
                //cout<<endword<<endl;
                auto it = m.find(endword);
                if(it != m.end() && it->second==level-1){
                    dfs(endword,v,level-1,beginword);
                }
            }
            endword[i] = o;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,0});
        st.erase(beginWord);
        int level=0;
        while(!q.empty()){
            string word =q.front().first;
            level=q.front().second;
            q.pop();
            //used.clear();
           m[word]=level;
            if(word==endWord){
                break;
            }
            for(int i =0; i<word.size(); i++){
                char ori = word[i];
                for(char ch = 'a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(st.count(word)>0){
                       q.push({word,level+1});
                        st.erase(word);
                    }
                }
                word[i] = ori;
            }
           // level++;
            
        }
       // cout<<m[wordList[0]]<<endl;
       
        dfs(endWord,{},m[endWord],beginWord);
        return ans;
    
        
    }
};