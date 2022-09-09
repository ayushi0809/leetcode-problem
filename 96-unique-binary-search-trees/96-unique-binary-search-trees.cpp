class Solution {
public:
    int numTrees(int n) {
       vector<int> v(n+1);
        v[0] = 1;
        v[1] = 1;
        int i;
        for(i = 2; i<=n; i++){
            v[i] = 0;
            for(int j = 1; j<=i; j++){
                v[i] = v[i]+ v[j-1]*v[i-j];
            }
        }
        return v[n];
        
        
    }
};