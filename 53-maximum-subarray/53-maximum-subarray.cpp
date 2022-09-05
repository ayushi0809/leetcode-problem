class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()<=1)
            return nums[0];
        int maxi = nums[0];
        int sum =0;
        if(nums[0]>0){
            sum = nums[0];
        }
        for(int i =1; i<nums.size(); i++){
            sum = sum+nums[i];
             maxi = max(maxi,sum);
            if(sum<0)
                sum = 0;
           
        }
        //maxi = max(sum,maxi);
        return maxi;
        
    }
};