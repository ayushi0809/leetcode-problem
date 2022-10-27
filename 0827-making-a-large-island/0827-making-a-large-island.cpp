class Disjointset{
    
    
    public:
    vector<int>rank, parent, size;
    int n;
    Disjointset(int v){
        n=v;
        rank.resize(v+1, 0);
        parent.resize(v+1);
        size.resize(v+1);
        for(int i =0; i<n; i++){
            parent[i] = i;
        }
        
        for(int i =0; i<n; i++){
            size[i] = 1;
        }
        
    }
    
    int findpar(int u){
        if(u==parent[u])
            return u;
        return parent[u] = findpar(parent[u]);
    }
    
    void unionbyrank(int u, int v){
        int ult_pu = findpar(u);
        int ult_pv = findpar(v);
        if(ult_pu == ult_pv)
            return;
        if(rank[ult_pu] < rank[ult_pv]){
            parent[ult_pu] = ult_pv;
        }
        else if(rank[ult_pv] < rank[ult_pu]){
            parent[ult_pv] = ult_pu;
        }
        else{
            parent[ult_pu] = ult_pv;
            rank[ult_pv]++;
        }
    }
    
    void unionbysize(int u, int v){
         int ult_pu = findpar(u);
        int ult_pv = findpar(v);
        if(ult_pu == ult_pv)
            return;
        if(size[ult_pu] < size[ult_pv]){
            parent[ult_pu] = ult_pv;
            size[ult_pv] +=size[ult_pu];
        }
        else{
             parent[ult_pv] = ult_pu;
            size[ult_pu] +=size[ult_pv];
        }
        
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        Disjointset ds(n*m);
        int ans = INT_MIN;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int i =0;i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == 1){
                   for(int k =0;k<4; k++){
                       int r = i+dr[k];
                       int c = j+dc[k];
                       if(r>=0 && r<n && c>=0 && c<n && grid[r][c] == 1){
                           int u = r*m+c;
                           int v = i*m+j;
                           if(ds.findpar(u) != ds.findpar(v)){
                               ds.unionbysize(u,v);
                           }
                       }
                   } 
                }
            }
        }
        int ult_p = ds.findpar(0);
        ans = ds.size[ult_p];
        
        for(int i =0; i<n; i++){
            for(int j =0;j<m; j++){
                if(grid[i][j] == 0){
                    int sum =0;
                    unordered_set<int>st;
                    for(int k =0;k<4; k++){
                       int r = i+dr[k];
                       int c = j+dc[k];
                       if(r>=0 && r<n && c>=0 && c<n && grid[r][c] == 1){
                           int u = r*m+c;
                          int p = ds.findpar(u);
                           st.insert(p);
                       }
                   }
                    for(auto it = st.begin(); it != st.end(); it++){
                        sum=sum+ds.size[*it];
                    }
                    ans = max(ans,sum+1);
                    
                }
            }
        }
        
        
        return ans;
    }
};