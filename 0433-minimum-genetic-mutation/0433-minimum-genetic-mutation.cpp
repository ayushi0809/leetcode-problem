class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        
        unordered_set<string>st(bank.begin(), bank.end());
        queue<pair<string,int>>q;
        vector<char>v = {'A', 'C', 'G', 'T'};
        
        q.push({start,0});
        unordered_map<string,int>m;
        m[start]= true;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            string s = it.first;
            int l = it.second;
            if(s==end){
                return l;
            }
            for(int i =0; i<8; i++){
                char ch = s[i];
                for(auto it : v){
                    s[i]=it;
                    if(st.find(s) != st.end() && m[s]== false){
                        m[s] = true;
                        q.push({s,l+1});
                    }
                }
                s[i] = ch;
            }
        }
        
        return -1;
        
    }
};