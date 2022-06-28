class Solution {
public:
    bool compare(string &s1, string &s2){
         
        if(s1.size() !=  s2.size()+1)
            return false;
        int i=0;
        int j =0;
        while(i<s1.size() ){
            if( j<s2.size() && s1[i]==s2[j]){
                i++;
                j++;
            }
              else{
                  i++;
              }  
        }
        if(i==s1.size() && j==s2.size())
            return true;
        return false;
    }
    static bool comp(string &s1, string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int m =1;
        vector<int>dp(n,1);
        sort(words.begin(),words.end(),comp);
        for(int i =0;i<n;i++){
            for(int j=0;j<i;j++){
                if(compare(words[i],words[j]) && 1+dp[j]>dp[i]){
                   dp[i] = 1+dp[j];
                    
                }
        }
            m = max(m,dp[i]);
        }
        return m;
    }
};