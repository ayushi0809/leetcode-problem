class Solution {
public:
    int f(int i, int n, int prev_ind, vector<int>& nums,  vector<vector<int>> &dp){
        if(i==n){
            return 0;
        }
        if(dp[i][prev_ind+1] != -1) return dp[i][prev_ind+1];
        int notpick = 0+f(i+1, n,prev_ind,nums,dp);
        if(prev_ind == -1 || nums[i]>nums[prev_ind]){
            prev_ind =i;
             notpick = max(notpick,1+f(i+1,n,prev_ind,nums,dp));
        }
       
        return dp[i][prev_ind+1] =  notpick;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i =n-1;i>=0;i--){
            for(int prev_ind = i-1; prev_ind>=-1; prev_ind--){
                int len = 0+dp[i+1][prev_ind+1];
                if(prev_ind == -1 || nums[i]>nums[prev_ind])
                    len = max(len,1+dp[i+1][i+1]);
                dp[i][prev_ind+1] = len;
            }
        }
        return dp[0][0];
    }
};