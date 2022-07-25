class Solution {
public:
    int f(int l, int r,vector<int>& nums, int target,bool flag ){
        int ans =-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target){
                ans = mid;
                if(flag){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
                
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0)
            return {-1,-1};
        int l = 0;
        int r = n-1;
        vector<int>v;
       int i = f(0,r,nums,target,true);
        if(i==-1)
            return {-1,-1};
        int j = f(0,r,nums,target,false);
        return {i,j};         
    }
};