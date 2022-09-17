class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=1){
            return n;
        }
        vector<vector<int>>dp(n, vector<int>(2,1));
        int res = 1;
        for(int i =0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[j] < nums[i]){
                    dp[i][0] = max(dp[i][0] , dp[j][1]+1);
                }
                else if(nums[j]>nums[i]){
                    
                    dp[i][1] = max(dp[i][1], dp[j][0]+1);
                    
                }
            }
            
            res = max(res, max(dp[i][0],dp[i][1]));
        }
        
        return res;
        
    }
};