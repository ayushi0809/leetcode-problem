class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int i =0;
        int sum =0;
        int maxsum = INT_MIN;
        while(i<n){
            sum = sum+nums[i];
            maxsum = max(maxsum,sum);
            if(sum<0){
                sum =0;
            }
            i++;
        }
        
        vector<int>pre(n);
        pre[0] = nums[0];
        vector<int>suf(n);
        suf[n-1] = nums[n-1];
         sum = nums[0];
        for(int i =1; i<n; i++){
            sum = sum+nums[i];
            pre[i] = max(sum,pre[i-1]);
        }
        
         sum = nums[n-1];
        for(int i = n-2; i>=0; i--){
            sum = sum+nums[i];
            suf[i] = max(sum,suf[i+1]);
        }
        
        for(int i =0; i<n-1; i++){
            maxsum = max(maxsum, pre[i]+suf[i+1]);
        }
        
        return maxsum;
        
    }
};