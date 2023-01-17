class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int flips = 0;
        int j =-1;
        int k =0;
        int n = s.size();
        vector<vector<int>>dp(2,vector<int>(n,0));
         for(int i =0; i<n; i++){
            if(s[i]=='1'){
               k=i;
                break;
            }
        }
        for(int i = n; i>=0; i--){
            if(s[i]=='0'){
                j=i;
                break;
            }
        }
        if(j==-1)
            return 0;
        
        
        for(int i = k; i<=j; i++){
            if(i==0){
                dp[0][i] = 0;
                dp[1][i] = 1;
            }
            else{
            if(s[i] == '1' && s[i-1] == '0'){
                dp[0][i] = min(dp[0][i-1],dp[1][i-1]);
                dp[1][i] = dp[0][i-1]+1;
            }
            else if(s[i-1] != s[i]){
                dp[0][i] = dp[1][i-1];
                dp[1][i] = dp[0][i-1]+1;
            }
           else if(s[i-1] == s[i]){
                dp[0][i] = dp[0][i-1];
                dp[1][i] = dp[1][i-1]+1;
            }
            }
        }
        
        
        return min(dp[0][j],dp[1][j]);
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         for(int i =0; i<n; i++){
//             if(s[i]=='1'){
//                k=i;
//                 break;
//             }
//         }
//         int i =k;
//         while(i<n){
//            // cout<<i<<endl;
//             if(s[i] == '1'){
//                // cout<<i<<endl;
//                 j = i;
//                 while(j<n && s[j] != '0'){
//                     j++;
//                     count1++;
//                 }
//                 while(j<n && s[j] != '1'){
//                     j++;
//                     count0++;
//                 }
//               // cout<<count0<<" "<<count1<<endl;

//                 flips = flips+min(count1,count0);
//                 count0=0;
//                 count1=0;
//             }
            
//             if(s[i] == '0'){
//                 j=i;
//                 while(j<n && s[j] != '1'){
//                     j++;
//                     count0++;
//                 }
//                 while(j<n && s[j] != '0'){
//                     j++;
//                     count1++;
//                 }
//                 flips = flips+min(count1,count0);
//                 count0=0;
//                 count1 =0;
//             }
            
//             i=j;
//             //cout<<i<<endl;
            
//         }
        
//         return flips;
        
    }
};