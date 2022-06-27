class Solution {
public:
    int f(int i,int n, int buy, int t, vector<int>& prices, vector<vector<vector<int>>> &dp){
        if(i==n || t>=2)
            return 0;
        int profit;
        if(dp[i][buy][t] != -1) return dp[i][buy][t];
        if(buy){
            return dp[i][buy][t] = max(-prices[i]+f(i+1,n,0,t,prices,dp), 0+f(i+1,n,1,t,prices,dp));
        }
        else{
            return dp[i][buy][t] = max(prices[i]+f(i+1,n,1,t+1,prices,dp), 0+f(i+1,n,0,t,prices,dp));
        }
        
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));
        for(int i =n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k =1;k<=2;k++){
                    if(j){
                        dp[i][j][k] = max(-prices[i]+dp[i+1][0][k], dp[i+1][1][k]);
                    }
                    else{
                        dp[i][j][k] = max(prices[i]+dp[i+1][1][k-1], dp[i+1][0][k]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};