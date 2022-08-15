class Solution {
public:
    int n,m;
    vector<int>delta = {0,1,0,-1,0};
    void dfs(int row, int col, vector<vector<int>>& grid){
        int count = 0;
        grid[row][col] = -grid[row][col];
        for(int i =0; i<4; i++){
            int r = row+delta[i];
            int c = col+delta[i+1];
            if(r>=0 && r<n && c>=0 && c<m){
                if(grid[row][col] == grid[r][c]){
                    count=count+1;
                }
                if(-grid[row][col] == grid[r][c]){
                    count=count+1;
                    dfs(r,c,grid);
                }
            }
        }
        if(count==4){
            grid[row][col] =-grid[row][col];
        }
    }
        
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        n = grid.size();
        m = grid[0].size();
        dfs(row,col,grid);
        
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j]<0){
                    grid[i][j] =color;
                }
            }
        }
        return grid;
    }
};