class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<int>>row;
        unordered_map<int,unordered_set<int>>col;
        int n = board.size();
       // int m = board[0].size();
       // cout<<'5'-'0'<<endl;
         for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                cout<<board[i][j]<<" ";
            }
             cout<<endl;
         }
        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                if(board[i][j] != '.'){
                if(row[i].find(board[i][j]-'0') == row[i].end()){
                    row[i].insert(board[i][j]-'0');
                }
                else{
                    cout<<board[i][j]<<endl;
                    return false;
                }
                }
            }
        }
        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                if(board[j][i] != '.'){
                if(col[i].find(board[j][i]-'0') == col[i].end()){
                    col[i].insert(board[j][i]-'0');
                }
                else{
                    
                    return false;
                }
                }
            }
        }
        int r =0; 
        int c =0;
        while(r<n){
            while(c<n){
            unordered_set<int>st;
           //out<<r<<" "<<c<<endl;
            for(int i =r; i<r+3; i++){
                for(int j =c; j<c+3; j++){
                    if(board[i][j] != '.'){
                        //ut<<i<<" "<<j<<endl;
                        if(st.find(board[i][j]-'0')==st.end()){
                            st.insert(board[i][j]-'0');
                        }
                        else{
                            return false;
                        }
                    }
                }
            }
            
           c=c+3;
        }
            c=0;
            r=r+3;
        }
        return true;
        
    }
};