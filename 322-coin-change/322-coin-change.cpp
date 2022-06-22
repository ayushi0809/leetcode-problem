class Solution {
public:
    int f(int i, int amount, vector<int>& coins, vector<vector<int>>&dp){
        if(i==0){
            if(amount%coins[0] ==0)
                return amount/coins[0];
            return 1e9;
        }
        if(dp[i][amount] != -1) return dp[i][amount];
        int notake = 0+f(i-1,amount,coins,dp);
        int take = 1e9;
        if(coins[i]<=amount){
            take = 1+f(i, amount-coins[i],coins,dp);
        }
        return dp[i][amount] = min(notake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1,-1));
        int x = f(coins.size()-1, amount, coins,dp);
            if(x != 1e9)
                return x;
        return -1;
    }
};