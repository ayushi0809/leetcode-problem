class Solution {
public:
    set<vector<int>>ans;
    void f(int i, int n, vector<int>v, vector<int>nums){
        if(i>=n){
            ans.insert(v);
            return;
        }
        
        f(i+1,n,v,nums);
        
        v.push_back(nums[i]);
        f(i+1,n,v,nums);
        v.pop_back();
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        f(0,nums.size(), {},nums);
        vector<vector<int>>v;
        for(auto it = ans.begin(); it!=ans.end(); it++){
            v.push_back(*it);
        }
        return v;
    }
};