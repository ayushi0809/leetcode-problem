class Solution {
public:
    //bool ans = true;
    bool f(int ind, int i, int j, int row, int col, string word, vector<vector<char>>& board,int k){
        if(ind ==k){
            return true;
        }
        if(i<0 || i>=row || j<0 || j>=col || board[i][j] != word[ind]){
            return false;
        }
        
        char tmp = board[i][j];
        board[i][j] = '$';
        bool r = f(ind+1, i+1,j,row,col,word,board,k);
        bool r1 = f(ind+1, i-1,j,row,col,word,board,k);
        bool c = f(ind+1, i,j+1,row,col,word,board,k);
        bool c1 =  f(ind+1, i,j-1,row,col,word,board,k);
        board[i][j] = tmp;
        return (r || r1 || c || c1);
            
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int s = word.size();
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(f(0,i,j,n,m,word,board,s))return true;
            }
        }
        return false;
    }
};