class Solution {
public:
    int findMin(vector<int>& nums) {
        int i =0;
        int j = nums.size()-1;
        int m = INT_MAX;
        int mid;
        if(nums[0]<nums[j]) return nums[0];
        while(i<=j){
            mid = (i+j)/2;
           cout<<mid<<endl;
           m = min(nums[i], nums[mid]);
           m = min(m,nums[j]);
            if(m == nums[mid]){
                j = mid;
                i++;
                
            }
            else if(m == nums[i]){
                j = mid-1;
            }
            else{
                i = mid+1;
            }
            
        }
        return m;
    }
       
};