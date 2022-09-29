class Solution {
public:
    int m ,n;
    void dfs(int row, int col, vector<vector<char>>&board, vector<vector<bool>>&vis){
       // cout<<row<<" "<<col<<endl;
        if(row<0 || row>=m || col<0 || col>=n || board[row][col] == 'X' || vis[row][col] == true  ){
            return;
        }
        vis[row][col] = true;
        board[row][col] = '$';
       // cout<<m<<" "<<n<<endl;
        dfs(row, col-1, board,vis);
        dfs(row, col+1, board,vis);
        dfs(row-1, col, board,vis);
        dfs(row+1, col, board,vis);
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n,false));
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                if(i==0 || i==m-1){
                    dfs(i,j,board,vis);
                }
                if(j==0 || j==n-1 ){
                    dfs(i,j,board,vis);
                }
            }
            }
        }
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(board[i][j] == '$'){
                    board[i][j] = 'O';
                }
                else{
                    board[i][j] = 'X';
                }
            }}
        
        //return board;
    }
};