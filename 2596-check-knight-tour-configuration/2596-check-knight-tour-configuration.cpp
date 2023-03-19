class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] != 0)
            return false;
        int i =0;
        int row =0;
        int col = 0;
        int s = n*n-1;
        
        while(i<s){
            if((row+2)<n && (col-1)>=0 && grid[row+2][col-1] == i+1){
                row = row+2;
                col = col-1;
            }
            else if((row+2)<n && (col+1)<n && grid[row+2][col+1] == i+1){
                row = row+2;
                col=col+1;
                
            }
            else if((row+1)<n && (col+2)<n && grid[row+1][col+2] == i+1){
                row = row+1;
                col = col+2;
            }
            else if((row-1)>=0 && (col+2)<n && grid[row-1][col+2] == i+1){
                row = row-1;
                col = col+2;
            }
            else if((row-2)>=0 && (col+1)<n && grid[row-2][col+1] == i+1){
                row = row-2;
                col=col+1;
            }
            else if((row-2)>=0 && (col-1)>=0 && grid[row-2][col-1] == i+1){
                row = row-2;
                col=col-1;
            }
            else if((row-1)>=0 && (col-2)>=0 && grid[row-1][col-2]== i+1){
                row = row-1;
                col = col-2;
            }
            else if((row+1)<n && (col-2)>=0 && grid[row+1][col-2] == i+1){
                row = row+1;
                col = col-2;
            }
            else{
                cout<<row<<col<<endl;
                return false;
            }
            
            
            
            i++;
        }
        
        return true;
        
    }
};