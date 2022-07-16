class Solution {
public:
    void dfs( vector<int>adj[] ,  vector<int> &entrytime, vector<int> &lowesttime, vector<vector<int>> &ans, int s, vector<bool> &visited, int c ){
        visited[s] = true;
        entrytime[s] = c;
        lowesttime[s] = c;
        for(auto a : adj[s]){
            if(!visited[a]){
                dfs(adj, entrytime, lowesttime, ans, a,visited, c+1);
                int mini = INT_MAX;
                for(auto x : adj[a] ){
                    
                    if(x != s){
                        mini = min(mini, lowesttime[x]);
                    }
                }
                lowesttime[a] = mini;
                if(lowesttime[a]>lowesttime[s]){
                    ans.push_back({a,s});
                }
            }
        }
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(int i =0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>entrytime(n);
        vector<int>lowesttime(n);
        vector<bool>visited(n, false);
        vector<vector<int>>ans;
        dfs(adj, entrytime, lowesttime, ans, 0,visited, 1);
        return ans;
    }
};