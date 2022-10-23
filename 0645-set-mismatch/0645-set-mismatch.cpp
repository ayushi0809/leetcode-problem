class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
         int n = nums.size();
        sort(nums.begin(), nums.end());
        int dup = -1;
        int miss = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] == nums[i]) {
                dup = nums[i];
            } else if (nums[i - 1] + 1 < nums[i]) {
                miss = nums[i - 1] + 1;
            }
        }
        return {dup, nums.back() != n ? n : miss};
    }
};