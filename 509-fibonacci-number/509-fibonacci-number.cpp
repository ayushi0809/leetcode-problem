// #define m 32
class Solution {
public:
    //int m = 32;
     int f(int n, vector<int> &ans) {
        if(n==0 || n== 1)
            return n;
        if(ans[n] != -1)
            return ans[n];
        
        return ans[n] = f(n-1,ans)+f(n-2,ans);
    }
   
    int fib(int n) {
         vector<int>ans(n+1,-1);
        return f(n,ans);
    }
};