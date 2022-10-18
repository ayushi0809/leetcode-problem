class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        set<int>st(restricted.begin(),restricted.end());
        vector<bool>vis(n,false);
        vector<int>adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);

        }
        queue<int>q;
        q.push(0);
        vis[0] = true;
        int count=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(auto it : adj[node]){
                if(vis[it]== false && st.find(it) == st.end()){
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
        
        return count;
        
    }
};