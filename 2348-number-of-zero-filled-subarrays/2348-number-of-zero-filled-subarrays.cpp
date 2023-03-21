class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans =0;
        int start =0;
        int end =0;
        int n = nums.size();
        long long zero=0;
        while(end<n){
            if(nums[end] !=0){
                long long a = end-start;
                zero = (a*(a+1))/2;
                ans = ans+zero;
                end++;
                start = end;
            }
            else{
            end++;
            }
        }
       
                long long a = end-start;
                zero = (a*(a+1))/2;
                ans = ans+zero;
            
        
        return ans;
        
    }
};