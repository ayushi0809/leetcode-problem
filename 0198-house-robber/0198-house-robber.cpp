class Solution {
public:
    int f(int i, int n, vector<int>& nums, vector<int> &dp){
        if(i>=n){
            return 0;
        }
        if(dp[i] != -1)
            return dp[i];
        int take = nums[i]+f(i+2,n,nums,dp);
        int notake =0+f(i+1,n,nums,dp);
        
        return dp[i] = max(take,notake);
    }
    int rob(vector<int>& nums) {
       
        int n = nums.size();
         vector<int>dp(n,-1);
        return f(0,n,nums,dp);
    }
};