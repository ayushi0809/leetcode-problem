class Solution {
public:
    struct hashFunction
{
  size_t operator()(const pair<int , 
                    int> &x) const
  {
    return x.first ^ x.second;
  }
};
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<int>adj[n];
        
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
       unordered_set<pair<int, int>, 
  hashFunction>st;
        for(auto it : connections){
            st.insert({it[0], it[1]});
        }
        
        vector<bool>vis(n, false);
        vis[0] = true;
        
        queue<int>q;
        q.push(0);
        int count =0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(vis[it]==false){
                if(st.find({it,node}) == st.end()){
                    count++;
                }
                    vis[it] = true;
                q.push(it);
                }
                
            }
        }
        
        return count;
        
    }
};