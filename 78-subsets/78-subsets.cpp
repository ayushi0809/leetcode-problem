class Solution {
public:
    vector<vector<int>>ans;
    void f(int i, int n, vector<int>v, vector<int>& nums){
        if(i>=n){
            ans.push_back(v);
            return;
        }
       f(i+1,n,v,nums);
        
        v.push_back(nums[i]);
        f(i+1,n,v,nums);
        v.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        f(0,nums.size(), {},nums);
        
        return ans;
    }
};