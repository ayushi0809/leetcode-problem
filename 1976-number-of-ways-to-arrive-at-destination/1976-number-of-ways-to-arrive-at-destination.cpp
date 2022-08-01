class Solution {
public:
    const int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& road) {
        vector<pair<int,long long>>adj[n];
        int e = road.size();
        for(int i=0;i<e;i++){
            int u = road[i][0];
            int v = road[i][1];
            long long wt = road[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>>>pq;
        vector<long long>distance(n,LONG_MAX);
        pq.push({0,0});
        distance[0] = 0;
        vector<int>path(n);
        path[0] = 1;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            long long wt = it.first;
            for(auto a : adj[node]){
                if(wt+a.second<distance[a.first]){
                    distance[a.first] = wt+a.second;
                    path[a.first] = path[node]%mod;
                    pq.push({distance[a.first],a.first});
                }
                else if(wt+a.second == distance[a.first]){
                    path[a.first] = (path[a.first]+path[node])%mod;
                }
            }
        }
        
       // return count(0,n-1,0,distance[n-1],adj);
        return path[n-1];
        
        
    }
};