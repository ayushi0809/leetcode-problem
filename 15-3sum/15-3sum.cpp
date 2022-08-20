class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>v;
        for(int i =0; i<n; i++){
           int s = 0-nums[i];
            int l =i+1;
            int r = n-1;
            while(l<r){
                if(nums[l]+nums[r]==s){
                    v.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
                else if(nums[l]+nums[r]>s){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        vector<vector<int>>ans;
        for(auto it = v.begin(); it != v.end(); it++){
            ans.push_back(*it);
        }
        return ans;
        
    }
};