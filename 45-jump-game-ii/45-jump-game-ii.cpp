class Solution {
public:
    
    int f(vector<int>& nums, int i, int n, vector<int> &dp){
        if(i>=n-1)
            return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 1e9;
        for(int j= 1; j<=nums[i];j++){
            int x = 1+f(nums, i+j, n, dp);
            ans = min(ans ,x);
        }
        return dp[i] = ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return f(nums, 0,n,dp);
        
    }
};