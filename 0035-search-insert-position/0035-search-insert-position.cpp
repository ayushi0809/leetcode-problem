class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target<nums[0]){
            return 0;
        }
        int n = nums.size();
        int l =0;
        int r = n-1;
        int mid =0;
        while(l<=r){
            mid = (l+r)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid]>target){
                r = mid-1;
            }
            else{
                l=mid+1;
            }
        }
        if(target>nums[mid])
            return mid+1;
        return mid;
        
    }
};