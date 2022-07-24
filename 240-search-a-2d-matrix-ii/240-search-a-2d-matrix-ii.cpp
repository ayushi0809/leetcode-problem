class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size()-1;
        int i = 0;
        while(col >= 0 && i < row){
            if(target < matrix[i][col]){
                col--;
            }
            else if(target > matrix[i][col]){
                i++;
            }
            else{
                return true;
            }
        }
        return false;
        
    }
};