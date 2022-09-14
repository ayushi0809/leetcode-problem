class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m,0));
        int maxi = 0;
        //cout<<'1'-'0'<<endl;
        for(int i =0; i<m; i++){
           // cout<<matrix[0][i]<<endl;
            dp[0][i] = matrix[0][i]-'0';
            maxi = max(maxi,dp[0][i]);
        }
        for(int i =0; i<n; i++){
            dp[i][0] = matrix[i][0]-'0';
            maxi = max(maxi,dp[i][0]);
        }
        
       
       // cout<<dp[0][0]<<endl;
        for(int i =1; i<n; i++){
            for(int j =1; j<m; j++){
               int temp = min(dp[i-1][j-1], min(dp[i][j-1],dp[i-1][j]));
                if(matrix[i][j] != '0'){
                    dp[i][j] = temp+(matrix[i][j]-'0');
                    cout<<dp[i][j]<<endl;
                }
                else{
                dp[i][j] = 0;
                }
                 maxi = max(maxi,dp[i][j]);
            }
        }
        
        return maxi*maxi;
        
    }
};