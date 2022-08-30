class Solution {
public:
    int f(int i, int n, vector<int> cost, vector<int>&dp){
        if(i>=n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int step1 = cost[i]+f(i+1,n,cost,dp);
        int step2 = cost[i]+f(i+2,n,cost,dp);
        
        return dp[i] = min(step1,step2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int  n = cost.size();
        vector<int>dp(n,-1);
        int ans = f(0,n,cost,dp);
        int ans1 = f(1,n,cost,dp);
        
        return min(ans,ans1);
    }
};