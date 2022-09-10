class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>m;
        int n = nums.size();
        int sum = 0;
        int count =0;
        for(int i =0; i<n; i++){
            sum = sum + nums[i];
            if(sum == goal){
                count++;
            }
            if(m.find(sum-goal) != m.end()){
                auto it  = m.find(sum-goal);
                count = count+it->second;
            }
            
            m[sum]++;
        }
        return count;
    }
};