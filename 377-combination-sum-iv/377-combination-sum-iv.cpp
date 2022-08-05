class Solution {
public:
    int count =0;
    int f(int i, int target, vector<int>&nums,int n, vector<int>&dp){
        if(i==n){
            if(target==0)
                return 1;
            else 
                return 0;
            }
        if(dp[target] != -1)
            return dp[target];
        int take =0;
        if(nums[i]<=target){
            take = f(0,target-nums[i], nums,n,dp);
        }
        int nottake = f(i+1, target, nums,n,dp);
        
        return dp[target] = take+nottake;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(target+1,-1);
         return f(0,target,nums,n,dp);
        
    }
};