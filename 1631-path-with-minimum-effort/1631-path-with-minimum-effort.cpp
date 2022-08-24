class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>delta = {
            {1,0}, {-1,0}, {0,1},{0,-1}
        };
        
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>>pq;
        pq.push({0, {0,0}});
        int ans = INT_MIN;
        vector<vector<int>> v(n,vector<int>(m,INT_MAX));
        v[0][0] = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            // if(it.second.first == n-1 && it.second.second == m-1){
            //     return v[n-1][m-1];
            // }
            for(auto x : delta){
                int r = it.second.first+x[0];
                int c = it.second.second+x[1];
                if(r>=0 && r<n && c>=0 && c<m)
                {
                int diff = abs(heights[it.second.first][it.second.second] - heights[r][c]);
                int maxi = max(it.first,diff);
                    if(maxi<v[r][c]){
                        v[r][c] = maxi;
                        pq.push({maxi, {r,c}});
                    }
                         
                }
            }
        }
        
        return v[n-1][m-1];
    }
};