class Solution {
public:
    // int f(int i, int amount, vector<int>& coins, vector<vector<int>> &dp ){
    //     if(i==0){
    //         if(amount%coins[0] ==0)
    //             return 1;
    //         return 0;
    //     }
    //     if(dp[i][amount] !=-1) return dp[i][amount];
    //     int nottake = f(i-1, amount, coins,dp);
    //     int take =0;
    //     if(coins[i]<=amount){
    //         take = f(i,amount-coins[i],coins,dp);
    //     }
    //     return dp[i][amount] = nottake+take;
    // }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1,0));
        for(int i=0;i<=amount; i++){
            if(i%coins[0] ==0) dp[0][i] =1;
        }
        for(int i=1;i<n;i++){
            for(int j=0; j<=amount ; j++){
                int notake = dp[i-1][j];
                int take =0;
                if(coins[i]<=j)
                    take = dp[i][j-coins[i]];
                dp[i][j] = notake+take;
            }
        }
        return dp[n-1][amount];
    }
};