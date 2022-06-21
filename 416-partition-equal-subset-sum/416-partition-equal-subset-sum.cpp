class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalsum =0;
        for(auto x : nums){
            totalsum +=x;
        }
        if(totalsum%2)
            return false;
        int k = totalsum/2;
        vector<vector<bool>>dp(nums.size(), vector<bool>(k+1,0));
        for(int i =0;i<nums.size();i++){
            dp[i][0] = true;
        }
        if(nums[0]<=k) dp[0][nums[0]] = true;
        for(int i =1;i<nums.size();i++){
            for(int j =1; j<=k; j++){
                bool notake = dp[i-1][j];
                bool take = false;
                if(j>=nums[i]) take = dp[i-1][j-nums[i]];
                dp[i][j] = notake || take;
            }
        }
        return dp[nums.size()-1][k];
    }
};