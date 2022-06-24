class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
         
        string s = "";
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j =1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int i =n;
        int j =m;
        int ind = n+m-dp[n][m]-1;
        //cout<<n+m-dp[n][m]<<endl;
       
        for(int k =0;k<=ind;k++){
            //cout<<s<<endl;
            s=s+'$';
        }
        
        while(i>0 &&j>0){
            //cout<<s<<endl;
            if(str1[i-1] == str2[j-1]){
                s[ind] = str1[i-1];
                ind--;
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                s[ind] = str1[i-1];
                ind--;
                i--;
            }
            else{
                s[ind] = str2[j-1];
                ind--;
                j--;
            }
        }
        while(i){
            s[ind] = str1[i-1];
            i--;
            ind--;
        }
        while(j){
            s[ind] = str2[j-1];
            j--;
            ind--;
        }
        
        return s;
        
    }
};