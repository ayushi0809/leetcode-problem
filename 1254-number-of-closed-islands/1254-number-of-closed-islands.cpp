class Solution {
public:
int n,m;
    void dfs(int row, int col, vector<vector<int>>& grid){
        if(row<0 || row>=n || col<0 || col>=m || grid[row][col] == 1 || grid[row][col] == -1){
            return;
        }
        grid[row][col] = -1;
        dfs(row,col-1,grid);
        dfs(row,col+1,grid);
        dfs(row-1,col,grid);
        dfs(row+1,col,grid);

    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int count =0;

        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(i==0 || i ==n-1){
                    if(grid[i][j] == 0){
                        dfs(i,j,grid);
                    }
                }
                 if(j==0 || j==m-1){
                    if(grid[i][j]==0 ){
                        dfs(i,j,grid);
                    }
                }
            }
        }
         for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j]==0){
                    count++;
                    dfs(i,j,grid);
                }
            }
            }
            return count;
    }
};