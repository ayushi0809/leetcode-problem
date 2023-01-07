class Solution {
public:
    int n,m;
    int isinterLeave(int i, int j,string s1, string s2, string s3, vector<vector<int>>&dp){
        if(i>=n)
            return s2==s3;
        if(j>=m)
            return s1==s3;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        if(s1[0] == s3[0]){
            //cout<<s1[i]<<" "<<s3[k]<<" "<<i<<" "<<k<<endl;
            ans = ans || isinterLeave(i+1,j,s1.substr(1), s2, s3.substr(1),dp);
        }
        if(s2[0] == s3[0]){
            ans = ans || isinterLeave(i,j+1,s1, s2.substr(1),s3.substr(1),dp);
        }
        //return ans;
        return dp[i][j] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size() != s3.size()){
            return false;
        }
         n = s1.size();
         m = s2.size();
       vector<vector<int>>dp(n, vector<int>(m,-1));
        int ans = isinterLeave(0,0,s1,s2,s3,dp);
        
        // for(int i =0; i<n;i++){
        //     for(int j =0; j<m; j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return ans;
       
    }
};