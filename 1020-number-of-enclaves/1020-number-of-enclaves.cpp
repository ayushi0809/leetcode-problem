class Solution {
public:
    int m,n;
    void dfs(int row, int col, vector<vector<int>>& grid){
        if(row<0 || row>=m || col<0 || col>=n || grid[row][col] == 0 || grid[row][col] == -1)
            return;
        grid[row][col] = -1;
        dfs(row, col-1,grid);
        dfs(row,col+1,grid);
        dfs(row-1,col,grid);
        dfs(row+1,col,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
         m = grid.size();
         n = grid[0].size();
        
        
        for(int i =0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i==0 || i ==m-1){
                    dfs(i,j,grid);
                }
                if(j==0 || j == n-1){
                    dfs(i,j,grid);
                }
            }
        }
        int count =0;
         for(int i =0; i<m; i++){
            for(int j = 0; j<n; j++){
               if(grid[i][j] == 1){
                   count++;
               } 
            }
         }
        return count;
    }
};