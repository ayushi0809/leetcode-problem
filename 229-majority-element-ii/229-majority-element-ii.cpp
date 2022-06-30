class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = floor(nums.size()/3);
        unordered_map<int,int>m;
        vector<int>v;
        for(auto x : nums){
            m[x]++;
        }
        for(auto it = m.begin(); it !=m.end();it++){
            if(it->second>n){
                v.push_back(it->first);
            }
        }
        return v;
    }
};