class Solution {
public:
     bool ans = false;
    int dp[50001];
    bool f(vector<int>& arr, int start, int n){
        if(start <0 || start >=n)
            return false;
        if(dp[start] != -1)
            return false;
        dp[start] = 1;
        if(arr[start] ==0)
            return true;
            
            ans = f(arr, start-arr[start],n) || f(arr, start+arr[start], n);
            
            
        
        return ans;
    }
    bool canReach(vector<int>& arr, int start) {
        memset(dp,-1,sizeof(dp));
        int n = arr.size();
        return f(arr, start,n);
    }
};