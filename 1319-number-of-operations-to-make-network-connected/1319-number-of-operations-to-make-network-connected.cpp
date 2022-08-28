class Solution {
public:
    void dfs(int i, vector<int>adj[], vector<bool> &visited){
        visited[i] = true;
        for(auto a : adj[i]){
            if(!visited[a]){
            dfs(a,adj,visited);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        if(n-1 > connections.size()){
            return -1;
        }
        for(auto it : connections){
            int u = it[0];
            int v  = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count =0;
        vector<bool>visited(n,false);
        for(int i =0; i<n; i++){
            if(!visited[i]){
                count++;
                dfs(i,adj,visited);
            }
        }
        
        return count -1;
    }
};