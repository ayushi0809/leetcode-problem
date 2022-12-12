class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<long long int,int>m;
        for(int i =0; i<nums.size(); i++){
            m[nums[i]]=i;
        }
        int ans = INT_MIN;
        for(int i =0; i<nums.size()-1;i++){
           int count =1;
            long long  int s = (long long)nums[i]*nums[i];
            while(m.find(s) != m.end()){
                count++;
                long long int sq = s*s;
                s=sq;
            }
            
            ans = max(count,ans);
        }
        if(ans == 1)
            return -1;
        return ans;
        
    }
};