class Solution {
public:
//     int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
//         if(j<0 || j>=matrix[0].size())
//             return 1e9;
//         if(i==0)
//             return matrix[i][j];
//         if(dp[i][j] != -1) return dp[i][j];
//         int u = matrix[i][j]+f(i-1, j, matrix,dp);
//         int ld = matrix[i][j]+f(i-1, j-1, matrix,dp);
//         int rd = matrix[i][j]+f(i-1, j+1, matrix,dp);
        
//         return dp[i][j] = min(u,min(ld,rd));
        
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         int x = INT_MAX;
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         for(int j =0; j<m;j++){
//             x = min(x,f(n-1,j,matrix,dp));
//         }
//         return x;
//     }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int x = INT_MAX;
        int u;
        int ld;
        int rd;
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int j =0; j<m;j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i =1; i<n; i++){
            for(int j =0; j<m;j++){
                 u = matrix[i][j] + dp[i-1][j];
                if(j-1<0){
                   ld = 1e9; 
                }
                else{
                   ld  = matrix[i][j] + dp[i-1][j-1]; 
                }
                if(j+1>=m){
                    rd = 1e9;
                }
                else{
                    rd = matrix[i][j] + dp[i-1][j+1];
                }
                dp[i][j] = min(u, min(ld,rd));
            }
        }
        for(int j =0; j<m;j++){
            x = min(dp[n-1][j],x);
        }
        return x;
    }
};