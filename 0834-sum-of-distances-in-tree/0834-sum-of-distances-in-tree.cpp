#define INF 99999
class Solution {
public:
    void dfs(vector<int>adj[], int curr, int parent, vector<int> &res, vector<int> &count){
        for(auto it : adj[curr]){
            if(it == parent)continue;
            dfs(adj, it, curr,res,count);
            cout<<curr<<" "<<it<<endl;
            count[curr] = count[curr]+count[it];
            res[curr] = res[curr]+res[it]+count[it];
        }
    }
    
    void dfs1(vector<int>adj[], int curr, int parent, vector<int> &res, vector<int> &count, int n){
        for(auto it : adj[curr]){
            if(it == parent)continue;
            res[it] = res[curr] - count[it]+ n-count[it]; 
            dfs1(adj,it,curr,res,count,n);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        //vector<vector<int>>mat(n,vector<int>(n));
        vector<int>res(n,0);
        vector<int>count(n,1);
        dfs(adj,0,-1,res,count);
        dfs1(adj,0,-1,res,count,n);
        
        
        // for(auto it : count){
        //     cout<<it<<endl;
        // }
        return res;

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         vector<vector<int>>mat(n,vector<int>(n,INF));
//         vector<int>ans(n);
//         for(auto it : edges){
//             int u = it[0];
//             int v = it[1];
//             mat[u][v] = 1;
//             mat[v][u] = 1;
//         }
//         for(int i =0; i<n; i++){
//             mat[i][i] = 0;
//         }
        
//         for(int k =0; k<n; k++){
//             for(int i =0; i<n; i++){
//                 for(int j =0; j<n; j++){
//                     if (mat[i][j] > (mat[i][k] + mat[k][j])
//                     && (mat[k][j] != INF
//                         && mat[i][k] != INF))
//                     mat[i][j] = mat[i][k] + mat[k][j];
//                 }
//             }
//         }
        
//         for(int i =0; i<n; i++){
//             int sum =0;
//             for(int j =0; j<n; j++){
//                 sum = sum+mat[i][j];
//             }
//             ans[i] = sum;
//         }
        
//        return ans;
        
    }
};