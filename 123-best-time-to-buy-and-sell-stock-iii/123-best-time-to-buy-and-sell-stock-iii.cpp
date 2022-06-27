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
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return f(0,n, 1, 0, prices,dp);
    }
};