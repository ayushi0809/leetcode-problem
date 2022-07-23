class Solution {
public:
    int find(int x, vector<int> &parent){
        if(parent[x]==x)
            return x;
        return parent[x] = find(parent[x],parent);
    }
    void unio(int u, int v, vector<int>&parent){
        parent[u] = v;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parent(n+1);
        for(int i =1; i<=n; i++){
            parent[i] =i;
        }
        for(int i =0;i<n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            //unio(u,v,parent);
            int parent_u = find(u,parent);
            int parent_v = find(v,parent);
            if(parent_u==parent_v){
                return edges[i];
            }
            unio(parent_u, parent_v, parent);
        }
        return {};
    }
};