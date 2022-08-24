class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n =grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1){
            return -1;
        }
        
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        grid[0][0] = -1;
        vector<vector<int>> delta = {
            {1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}
        };
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            // cout<<it.first.first <<" "<<it.first.second<<endl;
            if(it.first.first == n-1 && it.first.second == m-1){
                return it.second;
            }
            for(auto x : delta){
                int r = it.first.first+x[0];
                int c = it.first.second+x[1];
                if(r>=0 && r<n && c>=0 && c<m && grid[r][c] == 0){
                    
                    grid[r][c] = -1;
                    q.push({{r,c},it.second+1});
                }
            }
            
            
        }
        return -1;
        
    }
};