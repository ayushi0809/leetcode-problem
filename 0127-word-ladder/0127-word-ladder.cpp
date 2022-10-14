class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string w = q.front().first;
            int level = q.front().second;
            q.pop();
            if(w==endWord)
                return level;
            string ori = w;
            for(int i =0; i<w.size(); i++){
                for(char ch ='a'; ch<='z'; ch++){
                    w[i]=ch;
                    if(st.find(w) != st.end()){
                        st.erase(w);
                        q.push({w,level+1});
                    }
                }
                w=ori;
            }
        }
        return 0;
    }
};