class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>dp(m, vector<int>(n,0));
        
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
           for(int i =0; i<m; i++){
               for(int j =0; j<n; j++){
                   int row1 = i-k;
                   int col1 = j-k;
                   int row2 = i+k;
                   int col2 = j+k;
                   
                   if(row1<0)row1=0;
                   if(col1<0)col1=0;
                   if(row2>=m)row2 = m-1;
                   if(col2>=n)col2=n-1;
                   
                   if(row1==0 && col1 != 0){
                       mat[i][j] = dp[row2][col2]-dp[row2][col1-1];
                   }
                   else if(col1 == 0 && row1 !=0){
                     mat[i][j] = dp[row2][col2]-dp[row1-1][col2];   
                   }
                   else if(row1==0 && col1 ==0){
                       mat[i][j] = dp[row2][col2];
                   }
                   else{
                       mat[i][j] = dp[row2][col2]-dp[row1-1][col2]-dp[row2][col1-1]+dp[row1-1][col1-1];
                   }
               }
           }
        
        return mat;
    }
};