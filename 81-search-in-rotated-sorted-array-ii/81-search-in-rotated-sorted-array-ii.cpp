class Solution {
public:
    bool f(vector<int>&nums, int l, int r, int target){
        if(l<=r){
           int mid = (l+r)/2;
            if(target==nums[mid]){
                return true;
            }
            else{
               return f(nums,l,mid-1,target) || f(nums,mid+1,r,target);
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l =0;
        int r = n-1;
        
       
            
        return f(nums,l,r,target);
        
    }
};