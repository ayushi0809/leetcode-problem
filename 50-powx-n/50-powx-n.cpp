class Solution {
public:
    // double f(double x, int n){
    //     if(n==0)
    //         return 1;
    //     return x *f( x,n-1);
    // }
    double myPow(double x, int n) {
        // if(n<0){
        //     x=1/x;
        //     n=-n;
        // }
        // return f(x,n);
        double ans = 1.0;
        long nn = n;
        if(nn<0) nn = -1.0*nn;
        while(nn>0){
            if(nn%2==1){
                ans = ans*x;
                nn=nn-1;
            }
            else{
                x=x*x;
                nn=nn/2;
            }
        }
        if(n<0) ans = double(1.0)/double( ans);
        return ans;
    }
};