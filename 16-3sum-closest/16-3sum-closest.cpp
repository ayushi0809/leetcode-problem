class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int closet = INT_MAX;
        int ans;
        for(int i =0; i<n; i++){
            int l = i+1;
            int r = n-1;
            
            while(l<r){
                if(nums[i]+nums[l]+nums[r] == target){
                    return target;
                }
                else if(nums[i]+nums[l]+nums[r]<target){
                    if(abs(target-(nums[i]+nums[l]+nums[r]))<=closet){
                    closet = abs(target-(nums[i]+nums[l]+nums[r]));
                    ans = nums[i]+nums[l]+nums[r];
                    }
                    l++;
                    //r--;
                }
                else{
                    if(abs(target-(nums[i]+nums[l]+nums[r]))<=closet){
                    closet = abs(target-(nums[i]+nums[l]+nums[r]));
                    ans = nums[i]+nums[l]+nums[r];
                    }
                    r--;
                    
                }
                
            }
        }
        return ans;
    }
};