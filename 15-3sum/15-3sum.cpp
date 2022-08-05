class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>v;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i =0;i<n; i++){
            int l = i+1;
            int r = n-1;
            if(i>0 && nums[i] == nums[i-1])
                continue;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]==0){
                    v.push_back({nums[i], nums[l], nums[r]});
                    l=l+1;
                    while(nums[l] == nums[l-1] && l<r)
                        l=l+1;
                    
                }
                else if(nums[i]+nums[l]+nums[r] > 0){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
       
        return v;
    }
};