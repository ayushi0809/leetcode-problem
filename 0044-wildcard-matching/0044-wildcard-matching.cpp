class Solution {
public:
    int n,m;
    bool IsMatch(string &s, string &p,int i, int j,vector<vector<int>> &dp){
        // if(s=="" && p ==""){
        //     return true;
        // }
        // if(p == "*"){
        //     return true;
        // }
        // if((s != "" && p == ""))
        //     return false;
        if(i>=n && j>=m){
            return true;
        }
        if(p.substr(j) == "*"){
            return true;
        }
        if(i<n && j>=m){
            return false;
        }
        bool ans = true;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i>=n && p[j] =='*' ){
            ans  = ans && (IsMatch(s,p,i,j+1,dp));
        }
        else if(i<n && p[j]=='*'){
            ans = ans && (IsMatch(s,p,i,j+1,dp) || IsMatch(s,p,i+1,j+1,dp) || IsMatch(s,p,i+1,j,dp));
        }
        else if(i<n && p[j]=='?'){
            ans = ans && IsMatch(s,p,i+1,j+1,dp);
        }
       else if(i<n && s[i] == p[j]){
            ans = ans && IsMatch(s,p,i+1,j+1,dp);
        }
       else if(s[i] != p[j]){
            return false;
        }
        
        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
         n = s.size();
         m = p.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return IsMatch(s,p,0,0,dp);
    }
};