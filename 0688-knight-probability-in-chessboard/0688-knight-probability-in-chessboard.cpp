class Solution {
public:
    long double moves(int n, int k, int i, int j, vector<vector<vector<long double>>>&dp){
        if(i<0 || i>=n || j<0 || j>=n){
            return 0;
        }
        if(k==0){
            return 1;
        }
        long double a =0;
        if(dp[k][i][j] != -1){
            return dp[k][i][j];
        }
        a = a+moves(n,k-1,i-2,j+1,dp);
        a = a+moves(n,k-1,i-2,j-1,dp);
        a = a+moves(n,k-1,i+2,j+1,dp);
        a = a+moves(n,k-1, i+2,j-1,dp);
        a = a+moves(n,k-1,i+1,j+2,dp);
        a = a+moves(n,k-1,i-1,j+2,dp);
        a = a+moves(n,k-1,i+1,j-2,dp);
        a = a+moves(n,k-1, i-1, j-2,dp);
        
        
        return dp[k][i][j] = a;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<long double>>>dp(k+1, vector<vector<long double>>(n+1 , vector<long double>(n+1,-1)));
        long double steps = moves(n,k,row,column,dp);
       // cout<<steps<<endl;
        double p = pow(8,k);
        
        double ans = steps/p;
        
        return ans;
    }
};