class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>v(n);
        vector<int>indegree(n,0);
        vector<int>adj[n];
        queue<int>q;
        for(int i =0; i<edges.size(); i++){
            int u = edges[i][0];
            int v= edges[i][1];
            adj[u].push_back(v);
        }
        for(int i =0; i<n; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        //cout<<indegree[3]<<" "<<indegree[4]<<" "<<indegree[5]<<" "<<endl;
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int x = q.front();
            for(auto it : adj[x]){
                for(auto j: v[x]){
                    if(find(v[it].begin(), v[it].end(),j) == v[it].end()){
                    v[it].push_back(j);
                    }
                }
                v[it].push_back(x);
                sort(v[it].begin(), v[it].end());
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
            q.pop();
        }
        return v;
    }
};