class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       
        queue<pair<pair<int,int>,int>>q;
        vector<int> delta = {0,1,0,-1,0};
        int n = mat.size();
        int m = mat[0].size();
         vector<vector<bool>>vis(n, vector<bool>(m,false));
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = true;
                }
            }
        }
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c = it.first.second;
            int count = it.second;
            mat[r][c] = count;
            for(int i =0; i<4; i++){
                int row = r+delta[i];
                int col = c+delta[i+1];
                if(row>=0 && row<n && col>=0 && col<m && vis[row][col] == false){
                    vis[row][col] = true;
                    q.push({{row,col}, count+1});
                }
            }
            
        }
        return mat;
    }
};