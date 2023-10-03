class Solution {
public:
    
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it : nums){
            mp[it]++;
        }
        int count = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            count = count+(it->second*(it->second-1))/2;
        }
        return count;
        
    }
};