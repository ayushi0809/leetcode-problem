class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l =0;
        int r = nums.size()-1;
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        while(l<=r){
            int mid = (l+r)/2;
            if(mid == 0){
                if(nums[mid] != nums[mid+1]){
                    return nums[mid];
                }
                else{
                    l=mid+1;
                }
            }
            else if(mid == n-1){
                if(nums[mid] != nums[mid-1]){
                    return nums[mid];
                }
                else{
                    r=mid-1;
                }
            }
            else if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }
        
        else if(mid %2 == 0 && nums[mid] == nums[mid-1]){
            r=mid-1;
        }
        else if(mid %2 == 0 && nums[mid] == nums[mid+1]){
            l = mid+1;
        }
            else{
               if(mid %2 != 0 && nums[mid] == nums[mid-1]){
                   l=mid+1;
               }
                else{
                    r=mid-1;
                }
            }
        }
        return 0;
    }
};