class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n,false));
        
        queue<pair<int, pair<int,int>>>q;
        
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                 if(mat[i][j] == 0){
                     q.push({0,{i,j}});
                     vis[i][j] = true;
                 }
            }
        }
        vector<int>delta = {0,1,0,-1,0};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int level = it.first;
            int r = it.second.first;
            int c = it.second.second;
            mat[r][c] = level;
            for(int i =0; i<4; i++){
                int row = r+delta[i];
                int col = c+delta[i+1];
                
                if(col>=0 && col<n && row>=0 && row<m && !vis[row][col]){
                    vis[row][col] = true;
                    q.push({level+1, {row,col}});
                }
            }
            
            
        }
        
        return mat;
    }
};