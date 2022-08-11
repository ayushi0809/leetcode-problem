class Solution {
public:
    vector<vector<int>>ans;
    void f(int i, int n, vector<int>v, vector<int> nums, int target){
        if(i>=n){
            return;
        }
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(nums[i]<=target){
            v.push_back(nums[i]);
            f(i,n,v,nums,target-nums[i]);
            //sum = sum-v[v.size()-1];
            v.pop_back();
        }
        
        f(i+1,n,v,nums,target);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        f(0,n,{},candidates,target);
        
        return ans;
    }
};