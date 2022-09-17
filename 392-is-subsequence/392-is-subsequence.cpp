class Solution {
public:
    bool f(int i, int j, string s, string t, int n, int m){
        if(j>=m && i<n){
            return false;
        }
        if(i>=n){
            return true;
        }
        if(s[i]==t[j]){
            return f(i+1,j+1,s,t,n,m);
        }
       return f(i,j+1,s,t,n,m);
    }
    bool isSubsequence(string s, string t) {
       int n = s.size();
        int m = t.size();
        
        return f(0,0,s,t,n,m);
        
    }
};