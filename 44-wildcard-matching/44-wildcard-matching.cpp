class Solution {
public:
    bool f(int i,int j, string &s, string &p, vector<vector<int>> &dp){
        if(j<0 && i<0)
            return true;
        if(j<0 && i>=0)
            return false;
        if(j>=0 && i<0){
            for(int k=0;k<=j;k++){
                if(p[k] !='*')
                    return false;
            }
            return true;
        }
        if(dp[j][i] != -1) return dp[j][i];
        if(s[i]==p[j] || p[j] == '?')
            return dp[j][i] = f(i-1,j-1,s,p,dp);
        if(p[j]=='*')
            return dp[j][i] = f(i-1,j,s,p,dp) || f(i,j-1,s,p,dp) ;
        return dp[j][i] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(n-1,m-1,s,p,dp);
        
    }
};