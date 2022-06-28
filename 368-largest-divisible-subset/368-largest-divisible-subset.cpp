class Solution {
public:
    // int f(int i, int n, int prev_ind, vector<int> nums){
    //     if(i==n)
    //         return 0;
    //     int len = 0+f(i+1,n,prev_ind,nums);
    //     if(prev_ind==-1 || nums[i]%nums[prev_ind] == 0){
    //         prev_ind =i;
    //         len = max(len, 1+f(i+1,n,prev_ind,nums));
    //     }
    //     return len;
    // }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>hash(n,0);
        int m =0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            hash[i] =i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(1+dp[j]>dp[i]){
                        dp[i] = 1+dp[j];
                    hash[i] = j; 
                    }   
                }
            }
            if(dp[i]>dp[m]){
                m=i;
            }
        }
        cout<<m<<endl;
        vector<int>v;
        while(hash[m] !=m){
           v.push_back(nums[m]) ;
            m=hash[m];
        }
        v.push_back(nums[m]);
        reverse(v.begin(),v.end());
        return v;
    }
};