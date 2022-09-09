class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1)
            return 1;
        vector<int>dp(n);
        dp[0] = 1;
        int l =0; 
        int j =0;
        int k =0;
        
        for(int i =1; i<n; i++){
            dp[i] = min(dp[l]*2, min(dp[j]*3, dp[k]*5));
            if(dp[i]== dp[l]*2)l++;
            if(dp[i] == dp[j]*3)j++;
            if(dp[i] == dp[k]*5)k++;
        }
        return dp[n-1];
    }
};