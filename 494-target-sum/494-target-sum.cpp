class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) {
        int n = arr.size();
        int totalsum =0;
        for(auto x : arr){
            totalsum+=x;
        }
        if(totalsum-target<0 || (totalsum-target)%2 !=0)
            return 0;
        int s2 = (totalsum-target)/2;
        vector<vector<int>>dp(n, vector<int>(s2+1,0));
        if(arr[0] == 0 ) dp[0][0] = 2;
    else dp[0][0] =1;
    if(arr[0] != 0 && arr[0]<=s2) dp[0][arr[0]] = 1;
    for(int i =1; i<n; i++){
        for(int j =0;j<=s2;j++){
            int notake = dp[i-1][j];
            int take =0;
            if(arr[i]<=j)
                take = dp[i-1][j-arr[i]];
            dp[i][j] = (notake+take);
        }
    }
    
    return dp[n-1][s2];
    }
};