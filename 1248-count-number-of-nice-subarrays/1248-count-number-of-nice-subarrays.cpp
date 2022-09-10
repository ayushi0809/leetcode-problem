class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            nums[i] = nums[i]%2;
        }
        
        unordered_map<int,int>m;
        int sum =0;
        int count = 0;
        for(int i =0; i<n; i++){
            sum = sum+nums[i];
            if(sum == k){
                count++;
            }
            if(m.find(sum-k) != m.end()){
                auto it = m.find(sum-k);
                count = count+it->second;
            }
            
            m[sum]++;
        }
        
        return count;
    }
};