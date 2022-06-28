class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>dp1(n,1);
        vector<int>bitonic(n);
        int m =0;
        for(int i =0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && 1+dp[j]>dp[i])
                    dp[i] = 1+dp[j];
            }
        }
        for(int i =n-1;i>=0;i--){
            for(int j=n-1;j>=i;j--){
                if(nums[j]<nums[i] && 1+dp1[j]>dp1[i])
                    dp1[i] =1+dp1[j];
            }
        }
        for(int i=0;i<n;i++){
            if(dp[i]>1 && dp1[i]>1){
            
            m= max(m,dp[i]+dp1[i]-1);
            }
        }
        cout<<m<<endl;
        return n-m;
    }
    
};