class Solution {
public:
    int f(int i, int j, int s, vector<int>&nums, vector<int>&multiplires,vector<vector<int>>&dp){
        if( s>=multiplires.size() || i>j ){
            return 0;
        }
        if(dp[i][s] != INT_MIN)
            return dp[i][s];
        int left = nums[i]*multiplires[s]+f(i+1,j,s+1,nums,multiplires,dp);
        int right = nums[j]*multiplires[s]+f(i,j-1,s+1,nums,multiplires,dp);
        
        
        return dp[i][s] = max(left,right);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,INT_MIN));
        return f(0,n-1, 0,nums,multipliers,dp);
        
    }
};