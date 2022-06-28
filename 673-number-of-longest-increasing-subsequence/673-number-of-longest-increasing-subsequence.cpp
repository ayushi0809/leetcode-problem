class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int m =0;
        int count =0;
        vector<int>dp(n,1);
        vector<int>h(n,1);
        for(int i=0;i<n;i++){
            for(int j =0;j<i;j++){
                if(nums[i]>nums[j] && 1+dp[j]>dp[i]){
                    dp[i] = dp[j]+1;
                h[i]=h[j];
                }
            
            else if(nums[i]>nums[j] && 1+dp[j] == dp[i] ){
                h[i] = h[j]+h[i];
            }
            }
            
          m=max(m,dp[i]);
          }
        
        
        for(int i=0;i<n;i++){
            if(dp[i]==m)
                count = count+h[i];
        }
    return count;
    }
};