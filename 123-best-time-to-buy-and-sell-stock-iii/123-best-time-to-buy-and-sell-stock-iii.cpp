class Solution {
public:
    int f(int i,int n, int t, vector<int>& prices, vector<vector<int>> &dp){
        if(i==n || t==4)
            return 0;
        int profit;
        if(dp[i][t] != -1) return dp[i][t];
        if(t%2==0){
            return dp[i][t] = max(-prices[i]+f(i+1,n,t+1,prices,dp), 0+f(i+1,n,t,prices,dp));
        }
        else{
            return dp[i][t] = max(prices[i]+f(i+1,n,t+1,prices,dp), 0+f(i+1,n,t,prices,dp));
        }
        
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(5,0));
        // vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));
        // vector<vector<int>>after(2, vector<int>(3,0));
        // vector<vector<int>>curr(2, vector<int>(3,0));
        // for(int i =n-1;i>=0;i--){
        //     for(int j=0;j<=1;j++){
        //         for(int k =1;k<=2;k++){
        //             if(j){
        //                 curr[j][k] = max(-prices[i]+after[0][k], after[1][k]);
        //             }
        //             else{
        //                 curr[j][k] = max(prices[i]+after[1][k-1], after[0][k]);
        //             }
        //         }
        //     }
        //     after = curr;
        // }
        // return after[1][2];
        for(int i=n-1;i>=0;i--){
            for(int t =3;t>=0;t--){
                if(t%2 ==0){
                    dp[i][t] = max(-prices[i]+dp[i+1][t+1], dp[i+1][t]);
                }
                else{
                    dp[i][t] = max(prices[i]+dp[i+1][t+1],dp[i+1][t]);
                }
            }
        }
        return dp[0][0];
    }
};