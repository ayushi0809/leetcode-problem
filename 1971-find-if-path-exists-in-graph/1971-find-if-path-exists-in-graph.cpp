class Solution {
public:
    void dfs(int i, vector<int>adj[], vector<bool>&visited){
       visited[i]=true;
        for(auto a : adj[i]){
            if(!visited[a]){
                dfs(a, adj,visited);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n];
        int size = edges.size();
        for(int i =0; i<size; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,false);
        dfs(source, adj, visited);
        return visited[destination];
    }
};