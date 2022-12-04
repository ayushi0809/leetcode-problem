class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 0;
        }
        vector<long long>v(n);
        v[0] = nums[0];
        for(int i = 1; i<n; i++){
            v[i] = v[i-1]+nums[i];
        }
        int ans;
        int m = INT_MAX;
        for(int i =0; i<n-1; i++){
            int s = abs(v[i]/(i+1) - (v[n-1]-v[i])/(n-i-1));
            if(s<m){
                ans = i;
                m=s;
            }
        }
        if(v[n-1]/n < m){
            ans = n-1;
        }
        
        return ans;
        
    }
};