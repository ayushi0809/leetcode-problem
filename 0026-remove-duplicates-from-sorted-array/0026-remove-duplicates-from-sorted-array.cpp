class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
       
        int i = 0, count=1;
        
        while(i < n-1){
            
            if( nums[i]!=nums[++i]) nums[count++] = nums[i];              
        }
        return count; 
    }
};