class Solution {
public:
    
    int f(vector<int>& nums, int i, int n, vector<int> &dp){
        if(i>=n-1)
            return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 1e9;
        for(int j= i+1; j<=i+nums[i];j++){
            ans = min(ans, 1+f(nums, j,n,dp));
        }
        return dp[i] = ans;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return f(nums,0,nums.size(),dp);
    }
};