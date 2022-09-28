class Solution {
public:
    string pushDominoes(string &s) {
        
      int n = s.size();
   // s[0] = '.';
        
       queue<pair<char,int>>q;
        for(int i =0; i<n; i++){
            if(s[i]== 'L' || s[i] == 'R'){
                q.push({s[i],i});
            }
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
           // cout<<s[it.second+1]<<" "<<s[it.second+2]<<endl;
            if(it.second > 0 && it.first == 'L'){
                if(s[it.second-1] == '.'){
                    s[it.second-1] = 'L';
                    q.push({s[it.second-1], it.second-1});
                }
            }
            if(it.first == 'R'){
                if(it.second < n-1 && s[it.second+1]=='.'){
                   // cout<<q.empty()<<endl;
                    if(it.second <n-2 && s[it.second+2] == 'L' && !q.empty()){
                        q.pop();
                        //cout<<q.empty()<<endl;
                    }
                    else{
                        s[it.second+1] = 'R';
                        q.push({s[it.second+1], it.second+1});
                    }
                }
            }
        }
        return s;
    }
};