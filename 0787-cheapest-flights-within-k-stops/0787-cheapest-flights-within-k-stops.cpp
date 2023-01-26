class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        int e = flights.size();
        for(int i =0; i<e; i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adj[u].push_back({v,wt});
        }
        queue<vector<int>>pq;
        pq.push({0, src,0});
        vector<int>distance(n,INT_MAX);
        distance[src] = 0;
        int i =0;
        while(!pq.empty()){
            auto it = pq.front();
            pq.pop();
            
            int node = it[1];
            int wt = it[0];
            int stops = it[2];
            cout<<node<<endl;
            for(auto a : adj[node]){
                if(distance[a.first]>wt+a.second && stops<=k){
                   // cout<<
                    distance[a.first] = wt+a.second;
                    pq.push({distance[a.first], a.first, stops+1});
                }
            }
        }
        // for(auto a : distance){
        //     cout<<a<<endl;
        // }
        if(distance[dst] == INT_MAX)
            return -1;
        return distance[dst];
    }
};