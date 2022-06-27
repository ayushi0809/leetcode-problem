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
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,0));
        dp[0][0] = true;
        for(int i =1;i<=n;i++){
            dp[0][i] = false;
        }
        for(int i=1;i<=m;i++){
            if(p[i-1] != '*')
                dp[i][0] = false;
            else
                dp[i][0] = dp[i-1][0];
        }
        for(int i =1;i<=m;i++){
            for(int j =1;j<=n;j++){
                if(p[i-1]==s[j-1] || p[i-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[i-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else{
                    dp[i][j] = false;
                }
            }
            
        }
        return dp[m][n];
        
    }
};