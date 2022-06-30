class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if(nums.size()<=1){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int secondmax = nums[nums.size()/2];
        int move =0;
        for(auto x : nums){
            move = abs(secondmax-x)+move;
        }
        return move;
    }
};