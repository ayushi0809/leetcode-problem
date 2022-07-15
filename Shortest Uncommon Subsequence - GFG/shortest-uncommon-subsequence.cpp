// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  int f(string &s, string &t, int n, int m, vector<vector<int>>&dp){
      if(n==0)
      return 1e5;
      if(m==0)
      return n;
      if(dp[n][m] != -1)
      return dp[n][m];
      int ans = INT_MAX;
       //int notmatch;
       int i;
       for( i =m-1; i>=0;i--){
           if(t[i]==s[n-1])
           break;
       }
       if(i==-1)
       ans  =1;
       else{
           ans = min(f(s,t,n-1,m,dp), f(s,t,n-1,i,dp)+1);
       }
       return dp[n][m] = ans;
      
  }
    int shortestUnSub(string S, string T) {
        // code here
        int n = S.size();
        int m = T.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        int l = f(S,T,n,m,dp);
        
        if( l == 1e5)
        return -1;
        return l;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}  // } Driver Code Ends