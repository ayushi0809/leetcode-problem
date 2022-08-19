class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 1;
       int ind = 2;
        for(int i =2; i<n; i++){
            if(nums[i]==nums[ind-2]){
                continue;
            }
            else{
                nums[ind] = nums[i];
                ind++;
            }
        }
        return ind;
    }
};