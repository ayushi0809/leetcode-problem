class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>>adj(n, vector<int>(n, int(1e6)));
        for(int i =0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            cout<<u<<" "<<v<<" "<<wt<<endl;
            adj[u][v]=wt;
            adj[v][u] = wt;
        }
        for(int i =0; i<n; i++){
            adj[i][i] =0;
        }
        
        for(int k =0; k<n; k++){
            for(int i =0; i<n; i++){
                for(int j =0; j<n; j++){
                    if (adj[i][j] > (adj[i][k] + adj[k][j])){
                    adj[i][j] = adj[i][k] + adj[k][j];
                    }
                }
            }
        }
        vector<int>v(n);
        int mini = INT_MAX;
        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                cout<<adj[i][j]<<" ";
                if(i!=j && adj[i][j]<=distanceThreshold){
                    v[i]++;
                }
                
            }
            mini = min(mini, v[i]);
            cout<<endl;
        }
        int ans = INT_MIN;
        for(int i =0; i<n; i++){
            if(v[i]==mini){
                ans = max(ans,i);
            }
        }
       return ans; 
        
    }
};