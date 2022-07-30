class Solution {
public:
    long long count;
    void dfs(int i , vector<int>adj[], vector<bool>&visited){
        visited[i] = true;
        for(auto a : adj[i]){
            if(!visited[a]){
                dfs(a,adj, visited);
            }
        }
        count++;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        // if(edges.size()==0)
        //     return (n*(n-1))/2;
        for(int i =0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,false);
        long long res = 0;
        long long N = n;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                count =0;
                dfs(i,adj,visited);
                cout<<res<<endl;
                res = res+((count*(N-count)));
            }
        }
        return res/2;
    }
};