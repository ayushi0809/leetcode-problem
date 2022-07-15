class Solution {
public:
    int count =0;
    int f(vector<vector<int>>& grid, int r, int c, int n,int m){
        if(r<0 || r>=n || c<0 || c>=m || grid[r][c] ==0 || grid[r][c] == -1)
            return 0;
        grid[r][c] = -1;
   return 1+f(grid, r-1,c,n,m)+f(grid, r+1, c,n ,m)+f(grid, r,c-1,n,m)+f(grid, r,c+1,n,m);
      
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int area = 0;
        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == 1){
                    area = max(area, f(grid, i,j,n,m));
                    //cout<<area<<endl;
                }
            }
        }
        return area;
    }
};