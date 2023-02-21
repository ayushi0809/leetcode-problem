class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l =0;
        int r = n-1;
        int mid =0;
        if(n==1){
            return nums[0];
        }
        if(nums[0] != nums[1]){
            return nums[0];
        }
        if(nums[n-1] != nums[n-2]){
            return nums[n-1];
        }
        while(l<=r){
            // cout<<l<<" "<<r<<" ";
            mid = (l+r)/2;
           // cout<<mid<<endl;
            if(mid == 0){
                if(nums[mid] != nums[mid+1]){
                    return nums[mid];
                }
                else {
                    l=mid+1;
                }
            }
            else if(mid == n-1){
                if(nums[mid] != nums[mid-1]){
                    return nums[mid];
                }
                else {
                    r=mid-1;
                }
            }
            
               // cout<<mid<<" "<<nums[mid]<<endl;
                else if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                    return nums[mid];
                }
               
            else if(mid%2 ==0 && nums[mid] == nums[mid-1]){
                r=mid-1;
            }
            else if(mid%2 == 0 && nums[mid] == nums[mid+1]){
                l=mid+1;
            }
            else{
                if(mid%2 !=0 && nums[mid] == nums[mid-1]){
                    l=mid+1;
                }
                    else{
                        r=mid-1;
                    }
                }
            }
            
        
        
        return -1;
    }
};