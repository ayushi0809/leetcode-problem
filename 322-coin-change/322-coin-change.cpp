class Solution {
public:
    // int f(int i, int amount, vector<int>& coins, vector<vector<int>>&dp){
    //     if(i==0){
    //         if(amount%coins[0] ==0)
    //             return amount/coins[0];
    //         return 1e9;
    //     }
    //     if(dp[i][amount] != -1) return dp[i][amount];
    //     int notake = 0+f(i-1,amount,coins,dp);
    //     int take = 1e9;
    //     if(coins[i]<=amount){
    //         take = 1+f(i, amount-coins[i],coins,dp);
    //     }
    //     return dp[i][amount] = min(notake,take);
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1,1e9));
        for(int i=0;i<amount+1;i++){
            if(i%coins[0]==0)
                dp[0][i] = i/coins[0];
        }
        for(int i =1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int notake = 0+dp[i-1][j];
                int take = 1e9;
                if(coins[i]<=j) take = 1+dp[i][j-coins[i]];
                dp[i][j] = min(notake,take);
            }
        }
        if(dp[n-1][amount]!= 1e9)
            return dp[n-1][amount];
        return -1;
    }
};