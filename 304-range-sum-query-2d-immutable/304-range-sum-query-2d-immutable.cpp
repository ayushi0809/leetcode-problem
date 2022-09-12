class NumMatrix {
public:
     vector<vector<int>>dp;
    NumMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
       dp = vector<vector<int>>(m,vector<int>(n,0));
        
        dp[0][0] = mat[0][0];
        
        for(int i =1; i<n; i++){
            dp[0][i] = dp[0][i-1]+mat[0][i];
        }
         for(int i =1; i<m; i++){
            dp[i][0] = dp[i-1][0]+mat[i][0];
        }
        
        for(int i =1; i<m; i++){
            for(int j =1; j<n; j++){
                dp[i][j] = mat[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(col1==0 && row1 != 0){
            return dp[row2][col2]-dp[row1-1][col2];
        }
        if(row1==0 && col1 != 0){
            return dp[row2][col2]-dp[row2][col1-1]; 
        }
        if(row1==0 && col1 ==0){
            return dp[row2][col2];
        }
        return dp[row2][col2]-dp[row1-1][col2]-dp[row2][col1-1]+dp[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */