class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 =0;
        int prev1 = nums[0];
        int curr1;
        //including the first index and excluding last one
        for(int i = 1; i<nums.size()-1; i++){
            int take = nums[i]; if(i>1) take+=prev2;
            int notake = 0+prev1;
            curr1 = max(take,notake);
            prev2 = prev1;
            prev1 = curr1;
        }
        curr1 = prev1;
        if(nums.size()<2){
            return curr1;
        }
         prev2 = 0;
        prev1 = nums[1];
        int curr2;
        
        //excluding last one and take including first one
        for(int i =2; i<nums.size(); i++){
            int take = nums[i]; if(i>2) take+=prev2;
            int notake = 0+prev1;
            curr2 = max(take,notake);
            prev2 = prev1;
            prev1 = curr2;
        }
        return max(curr1 , prev1);
    }
};