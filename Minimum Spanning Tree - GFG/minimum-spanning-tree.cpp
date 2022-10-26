//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Disjointset{
    vector<int>rank, parent, size;
    
    public:
    Disjointset(int v){
        rank.resize(v+1, 0);
        parent.resize(v+1);
        size.resize(v+1);
        for(int i =0; i<v; i++){
            parent[i] = i;
        }
        
        for(int i =0; i<v; i++){
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
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int, pair<int,int>>>edges;
        
        for(int i =0; i<V; i++){
            for(auto it : adj[i]){
                int adjnode = it[0];
                int wt = it[1];
                edges.push_back({wt, {adjnode,i}});
            }
        }
        Disjointset ds(V);
        sort(edges.begin(), edges.end());
        int sum =0;
        for(auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findpar(u) != ds.findpar(v)){
                sum =sum+wt;
                ds.unionbysize(u,v);
            }
        }
        
        return sum;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends