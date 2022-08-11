class Solution {
public:
    //set<vector
    vector<vector<int>>ans;
    void f(int i, int n, vector<int>v,vector<int>&candidates, int target){
        
            if(target==0){
            ans.push_back(v);
            return;
        }
        
        
        for(int j = i; j<n;j++){
            if(j>i && candidates[j] == candidates[j-1])continue;
            
            if(candidates[j]>target)
                break;
            
            v.push_back(candidates[j]);
            f(j+1,n,v,candidates,target-candidates[j]);
            v.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        f(0,n,{},candidates,target);
        
        return ans;
        
    }
};