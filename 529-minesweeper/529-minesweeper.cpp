class Solution {
public:
    int n ,m;
    vector<vector<int>> dir = {{-1,-1}, {1,1}, {0,1}, {1,0}, {-1,0}, {0,-1}, {1,-1}, {-1,1}};
    void f(int r, int c,  vector<vector<char>>& board){
        int count = 0;
       // vis[r][c] = true;
        board[r][c] = 'B';
        for(vector<int> d : dir){
             int row = r + d[0], col = c + d[1];
            if(row<0 || row>=n || col<0 || col>=m || board[row][col] != 'M' )continue;
                    count=count+1;
                    //return;
        }
                 if(count != 0){
                    board[r][c] = count+'0';
                 } else{
                      for(vector<int> d : dir){
             int row = r + d[0], col = c + d[1];
            if(row<0 || row>=n || col<0 || col>=m || board[row][col] != 'E' )continue;
                     board[row][col] = 'B';
                          f(row,col,board);
                 } 
                
            }
    }
        
        
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
         n  = board.size();
         m = board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int r = click[0];
        int c = click[1];
        if(board[r][c] == 'M'){
            board[r][c] = 'X';
           
            return board;
        }
        f(r,c,board);
        
        return board;
        
        
        
    }
};