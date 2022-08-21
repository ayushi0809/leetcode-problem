class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n =nums.size();
        set<vector<int>>v;
        for(int i =0; i<n; i++){
            for(int j =i+1; j<n; j++){
                int l = j+1;
                int r = n-1;
                while(l<r){
                    long long sum = (long long)(nums[i])+(long long)(nums[l])+(long long)nums[r]+(long long)nums[j];
                    if(sum == target){
                        v.insert({nums[i],nums[l],nums[r],nums[j]});
                        l++;
                        r--;
                    }
                    else if(sum>target){
                        r--;
                    }
                    else{
                        l++;
                    }
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