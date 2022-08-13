class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<int> delta = {0,1,0,-1,0};
        queue<pair<pair<int,int>,int>>q;
        
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == 1){
                    q.push({{i,j}, 0});
                    vis[i][j] = true;
                }
            }
        }
        int ans = -1;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c = it.first.second;
            int count = it.second;
            //cout<<count<<endl;
            ans = max(ans, it.second);
            
            for(int i =0; i<4; i++){
                int row = r+delta[i];
                int col = c+delta[i+1];
                if(row>=0 && row<n && col>=0 && col<m && vis[row][col] == false){
                    vis[row][col] = true;
                    q.push({{row,col}, count+1});
                }
            }
            
        }
        if(ans ==0 )
            return -1;
        return ans;
    }
};