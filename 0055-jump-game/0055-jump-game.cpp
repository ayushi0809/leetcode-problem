class Solution {
public:
   bool ans = false;
    bool f(vector<int> &nums, int n, int i, vector<int> &dp){
        if(i==n-1)
            return true;
        if(nums[i] ==0)
            return false;
        if(dp[i] !=-1 ) return dp[i];
        for(int j =1;j<=nums[i];j++){
            ans = ans || f(nums, n , i+j,dp);
        }
        return dp[i] =  ans;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool>dp(n,false);
       // return f(nums, n, 0, dp);
        dp[n-1] = true;
        
        for(int i = n-2; i>=0; i--){
            for(int j = 1; j<=nums[i]; j++){
                if(i+j<n){
                    dp[i] = dp[i] || dp[i+j];
                    if(dp[i] == true)
                        break;
                }
            }
        }
        
        return dp[0];
        
    }
};