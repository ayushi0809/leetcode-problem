class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>indegree(n,0);
        int size = edges.size();
        if(n<2){
            vector<int>height;
            for(int i =0; i<n; i++){
                height.push_back(i);
            }
            return height;
        }
       for(int i=0; i<size; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
           indegree[u]++;
           indegree[v]++;
        }
      queue<int>q;
        for(int i=0; i<n; i++){
            if(adj[i].size()==1){
                q.push(i);
                indegree[i]--;
            }
        }
        vector<int>v;
            while(q.size()){
                int s = q.size();
                v.clear();
                while(s){
                    int i = q.front();
                    q.pop();
                     v.push_back(i);
                    for(auto x : adj[i]){
                        indegree[x]--;
                        if(indegree[x]==1)
                            q.push(x);
                    }
                 s--;   
                }
            }
        return v;
        
    }
};