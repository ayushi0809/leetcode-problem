class Solution {
public:
    set<vector<int>>ans;
    bool isincreasing(vector<int>v){
        for(int i =0; i<v.size()-1; i++){
            if(v[i] > v[i+1])return false;
        }
        return true;
    }
    void f(int ind, int n, vector<int>&nums, vector<int>v){
        if(ind>=n){

        if(v.size() >=2 && isincreasing(v)){
            //cout<<v[0]<<" "<<v[1]<<endl;
            ans.insert(v);
            //return;
        }
             return ;
        }
        v.push_back(nums[ind]);
        f(ind+1, n, nums,v);
        v.pop_back();
        f(ind+1,n,nums,v);
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        f(0,nums.size(), nums, {});
       vector<vector<int>>v; 
        for(auto it =ans.begin(); it!=ans.end(); it++ ){
            v.push_back(*it);
        }
        return v;
    }
};