class Solution {
public:
    vector<string>ans;
    void GenPar(int l, int r, int n, string s){
        if(l==n && r==n){
           // cout<<s<<endl;
            ans.push_back(s);
            return;
        }
        if(l<n && l>=r){
           // s=s+'(';
            GenPar(l+1,r,n,s+'(');
            //cout<<s<<endl;
        }
        if(r<l){
            //s=s+')';
            GenPar(l,r+1,n,s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
     //GenPar(0,0,n,"");
       // vector<string>ans;
        vector<vector<vector<string>>>dp(n+1, vector<vector<string>>(n+1));
        dp[0][0] = {""};
        string s= "";
        for(int i =1; i<=n; i++){
            s=s+'(';
            dp[0][i]  = {s};
        }
        for(int i =0; i<=n; i++){
            dp[i][0] = {""};
        }
        for(int i =1; i<=n; i++){
            for(int j =1; j<=n; j++){
                if(i<=j){
                    if(i==j){
                        for(auto it : dp[i-1][j]){
                            dp[i][j].push_back(it+')');
                        }
                    
                    }
                    else{
                        for(auto it : dp[i-1][j]){
                            dp[i][j].push_back(it+')');
                        }
                        for(auto it : dp[i][j-1]){
                            dp[i][j].push_back(it+'(');
                        }
                        
                    }
                    
                }
                
                
                
            }
        }
        return dp[n][n];
    }
};