class Solution {
public:
    int f(int i, int buy, vector<int>& prices, vector<vector<int>> &dp){
        if(i==0){
            if(buy){
                return -prices[0];
            }
            return 0;
        }
        int profit;
        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy){
            profit = max(-prices[i]+f(i-1,0,prices,dp), 0+f(i-1,1,prices,dp));
        }
        else{
            profit = max(prices[i]+f(i-1,1,prices,dp), 0+f(i-1,0,prices,dp));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit;
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n][0] = dp[n][1] =0;
        for(int i =n-1;i>=0;i--){
            for(int j = 0;j<=1;j++){
                if(j){
                    profit = max(-prices[i]+dp[i+1][0], 0+dp[i+1][1]);
                }
                else{
                    profit = max(prices[i]+dp[i+1][1], 0+dp[i+1][0]);
                }
                dp[i][j] = profit;
            }
        }
        return dp[0][1];
    }
};