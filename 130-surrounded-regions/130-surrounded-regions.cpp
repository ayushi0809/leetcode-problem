class Solution {
public:
    int m,n;
    void dfs(int row, int col, vector<vector<char>>& baord){
        //ut<<row<<" "<<col<<endl;
        if(row<0 || row>=n || col<0 || col>=m || baord[row][col] == 'X' || baord[row][col]=='$'){
            return;
        }
        baord[row][col]='$';
      
        dfs(row-1, col,baord);
        dfs(row+1,col,baord);
        dfs(row, col+1, baord);
        dfs(row, col-1, baord);
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        vector<vector<int>>v(n, vector<int>(m,0));
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(i==0 || i==n-1){
                    dfs(i,j,board);
                }
                else{
                    dfs(i,0,board);
                    dfs(i,m-1,board);
                }
            }
        }
         for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(board[i][j]=='$'){
                    board[i][j]= 'O';
                }
                else{
                                        board[i][j]= 'X';

                }
            }}
            
            
    }
};