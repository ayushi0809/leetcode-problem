#define mod 1000000007
class Solution {
public:
    int numTilings(int n) {
        if(n<=2){
            return n;
        }
        vector<long long>v(n+1);
        v[1] = 1;
        v[2]= 2;
        v[3] = 5;
        for(int i =4; i<=n; i++){
            v[i] = (2*v[i-1]+v[i-3])%mod;
        }
        return v[n];
        
    }
};