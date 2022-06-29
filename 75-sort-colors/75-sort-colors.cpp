class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low =0;
        int mid =1;
        int high =2;
        int i=0;
        int k=0;
        int j = nums.size()-1;
        while(i<=j){
            if(nums[i]==high){
                swap(nums[i],nums[j]);
                j--;
                continue;
            }
            if(nums[i]==low){
                swap(nums[i],nums[k]);
                i++;
                k++;
                continue;
            }
           else{
               i++;
               continue;
           }
            
        }
        
        
    }
};