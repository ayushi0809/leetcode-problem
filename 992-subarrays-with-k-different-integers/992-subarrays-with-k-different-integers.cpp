class Solution {
public:
    int f(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>m;
        int i =0;
        int j =0;
        int count =0;
        
        while(j<n){
           
                m[nums[j]]++;
               
            while(m.size()>k){
                
                //count++;
                m[nums[i]]--;
                if(m[nums[i]]==0)m.erase(nums[i]);
                i++;
            }
            
            count = count+j-i+1;
             j++;
            
            
        }
        return count;
        
    }
     int subarraysWithKDistinct(vector<int>& nums, int k) {
         return f(nums,k)-f(nums,k-1);
     }
};