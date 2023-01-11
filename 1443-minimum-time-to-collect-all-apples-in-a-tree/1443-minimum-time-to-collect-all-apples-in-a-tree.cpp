class Solution {
public:
    int ans =0;
    set<pair<int,int>>s;
    void dfs(int i, int parent, vector<int>adj[], vector<bool>&vis,vector<bool>& hasApple, set<pair<int,int>>st ){
        vis[i] = true;
        for(auto a : adj[i]){
            if(!vis[a]){
                st.insert({i,a});
               // cout<<i<<" "<<a<<endl;
                dfs(a,i,adj,vis,hasApple,st ); 
                //cout<<a<<endl;
                if(hasApple[a]){
                    //cout<<a<<endl;
                    for(auto it : st){
                        s.insert(it);
                    }
                }
               // cout<<i<<" "<<a<<endl;
                st.erase({i,a});
            }
        }
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int>adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool>vis(n,false);
        set<pair<int,int>>st;
        dfs(0,-1,adj,vis,hasApple,st);
        // for(auto it : s){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
       // cout<<s.size()<<endl;
        int ans = 2*s.size();
        
        return ans;
        
    }
};