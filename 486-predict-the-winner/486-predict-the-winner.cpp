class Solution {
public:
    int f(vector<int> &nums, int i, int n, int chance){
       if(i==n)
           return chance* nums[i];
        int a = chance*nums[i]+f(nums,i+1,n,-chance);
        int b = chance*nums[n]+f(nums,i,n-1, -chance);
        
        return chance*max(chance*a, chance*b);
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int ans = f(nums, 0, n-1,1);
        return ans>=0;
    }
};