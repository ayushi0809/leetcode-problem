class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m = nums[0];
        int s;
        if(nums[0]<0) s=0;
        else
           s=nums[0];
        for(int i =1; i<nums.size(); i++){
            s=s+nums[i];
            m = max(m,s);
            if(s<0)
                s=0;
        }
        return m;
    }
};