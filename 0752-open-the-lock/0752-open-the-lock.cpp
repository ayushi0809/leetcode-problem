class Solution {
public:
   
    vector<string> modify(string key){
         vector<string>res;
        //cout<<key<<endl;
        for (int i = 0 ; i < 4; i++) {
            string tmp = key;
            tmp[i] = (key[i] - '0' + 1) % 10 + '0';
            res.push_back(tmp);
            tmp[i] = (key[i] - '0' - 1 + 10) % 10 + '0';
            res.push_back(tmp);
            //cout<<tmp<<endl;
         }
        return res;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>st(deadends.begin(), deadends.end());
        vector<int>dist(100000,1e9);
        if(st.find("0000") != st.end())
            return -1;
        queue<pair<string,int>>q;
        st.insert("0000");
        int ans = INT_MAX;
        dist[0] = 0;
        q.push({"0000",0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            string node = it.first;
            int l = it.second;
            if(node==target){
                 return l;
            }
            for(auto a : modify(node)){
                    
                    if(st.find(a)== st.end()){
                        st.insert(a);
                        q.push({a,l+1});
                    
                }
                
            }
            //res.clear();
        }
        if(ans == INT_MAX)
            return -1;
        return ans;
        
    }
};