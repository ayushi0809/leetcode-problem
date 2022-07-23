class Solution {
public:
    void dfs(int s, vector<int>adj[], vector<bool>&visited){
        visited[s]=true;
        for(auto a : adj[s]){
            if(!visited[a]){
            dfs(a,adj,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int>adj[V+1];
        for(int i =0; i<V; i++){
            for(int j =0; j<V; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        int count =0;
        vector<bool>visited(V+1, false);
        for(int i =1; i<=V; i++){
            if(!visited[i]){
                count++;
                dfs(i,adj,visited);
            }
        }
        return count;
    }
};