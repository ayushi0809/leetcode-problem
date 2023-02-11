class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<pair<int,int>>adj[n];
        
       for(auto it : redEdges){
           int u = it[0];
           int v = it[1];
           adj[u].push_back({v,0});
       }
         for(auto it : blueEdges){
           int u = it[0];
           int v = it[1];
           adj[u].push_back({v,1});
       }
        
        queue<pair<int,int>>q;
        vector<int>dist(n, 1e9);
        vector<vector<int>>vis(n, vector<int>(2,false));
        dist[0] = 0;
        q.push({0,0});
        q.push({0,1});
        vis[0][0] = true;
        vis[0][1] = false;
        int level =0;
        while(!q.empty()){
            int s = q.size();
            while(s){
                auto it = q.front();
                q.pop();
                int node = it.first;
                int color = it.second;
                dist[node]= min(dist[node], level);
                for(auto a : adj[node]){
                    if(vis[a.first][color] == false && a.second != color){
                        vis[a.first][color] = true;
                        q.push({a.first,a.second});
                    }
                }
             s--;   
            }
            level++;
        }
        for(int i =0; i<n; i++){
            if(dist[i] == 1e9){
                dist[i] = -1;
            }
        }
        return dist;
    }
};