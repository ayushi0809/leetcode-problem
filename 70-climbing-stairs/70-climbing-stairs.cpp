class Solution {
public:
    int v[46] = {-1};
    int f(int n, vector<int> &v){
        if(n==1 || n==2)
            return n;
        if(v[n] != -1)
            return v[n];
        int res = f(n-1,v)+f(n-2,v);
        return v[n] = res;
    }
    int climbStairs(int n) {
        vector<int>v(n+1,-1);
        return f(n,v);
        
    }
};