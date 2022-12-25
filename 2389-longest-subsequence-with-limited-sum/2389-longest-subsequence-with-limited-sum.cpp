class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        
        vector<int>prefix(nums.size());
        prefix[0] = nums[0];
        
        for(int i = 1; i<nums.size(); i++){
            prefix[i] = prefix[i-1]+nums[i];
        }
        
        vector<int>ans;
        
        for(auto it : queries){
            int ind = upper_bound(prefix.begin(), prefix.end(), it)-prefix.begin();
            ans.push_back(ind);
            
        }
        
        return ans;
        
    }
};