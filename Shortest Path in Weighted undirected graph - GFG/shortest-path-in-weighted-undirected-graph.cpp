//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>>adj[n+1];
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int>dist(n+1, 1e9);
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>>q;
        q.push({0,{1}});
        dist[1] = 0;
        vector<int>ans = {-1};
        int w = INT_MAX;
        while(!q.empty()){
        auto it = q.top();
        q.pop();
        vector<int>v = it.second;
        int d = it.first;
        int node = v.back();
        //cout<<node<<"  "<<d<<endl;
        if(node == n && d<w){
            w=d;
            ans = v;
        }
        for(auto a : adj[node]){
            if(dist[a.first] > a.second+d){
                dist[a.first] = a.second+d;
                v.push_back(a.first);
                q.push({dist[a.first], v});
                v.pop_back();
            }
            
        }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends