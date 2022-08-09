class Solution {
public:
    int m,n;
    vector<int> delta = {0,1,0,-1,0};
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis){
        cout<<row<<" "<<col<<endl;
         vis[row][col] = 1;
        for(int deli = -1; deli<=1; deli++){
                for(int delj = -1; delj<=1; delj++){
                    int nrow = row + deli;
                    int ncol = col + delj;
                    if((deli==-1 && delj==-1) ||(deli==-1 && delj==1) || (deli==1 && delj==-1) || (deli==1 && delj==1)) continue;
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol] == '1' && vis[nrow][ncol]== 0){
                dfs(nrow, ncol,grid,vis);
        }
        
    }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        //cout<<m<<" "<<n<<endl;
        vector<vector<int>>vis(m, vector<int>(n,0));
        int count =0;
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    count++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};