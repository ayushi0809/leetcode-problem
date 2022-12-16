class Solution {
public:
    static bool comparator(const pair<int,int> &a, const pair<int,int> &b){
        return a.second>b.second;
    }
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<pair<int,int>>adj[n];
        for(int i =0; i<edges.size(); i++){
            auto it = edges[i];
            adj[it[0]].push_back({it[1],vals[it[1]]});
            adj[it[1]].push_back({it[0],vals[it[0]]});
        }
        
        for(int i =0; i<n; i++){
            sort(adj[i].begin(),adj[i].end(), comparator);
            
        }
         int maxi = INT_MIN;
         for(int i =0; i<n; i++){
             maxi = max(maxi,vals[i]);
         }
       
        for(int i =0; i<n; i++){
            auto it = adj[i];
            int sum = vals[i];
            for(int j =0; j<it.size() && j<k; j++){
                auto a = it[j];
                // if(i==3){
                //     cout<<a.first<<" "<<a.second<<endl;
                // }
                if(a.second>0)
                    sum = sum+a.second;
            }
            maxi = max(maxi,sum);
        }
        
        return maxi;
        
        
    }
};