class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int s = 0;
        int s1 =0;
        for(int i =0; i<nums.size(); i++){
            s=s1 & (s^nums[i]);
            s1 = s | (s1^nums[i]);
        }
        return s1;
    }
};