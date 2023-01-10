class Solution {
public:
    int numDecod(vector<int> &dp,string s){
        int n = s.size();
         //cout<<s<<" "<<n<<endl;
        
        if(s.size()==0)
            return 0;
        if(s[0]=='0')
            return dp[n]=0;
        if(s.size()==1)
        {
            dp[1] =1;
            return 1;
        }
        if(s.size()==2 && stoi(s)<=26 &&stoi(s)>=1)
        {
            if(s[1]=='0')
            {
                dp[2]=1;
                return 1;
            }
            dp[2]=2;
            return 2;
        }
        int left =0;
        int right =0;
        if(dp[n]!=-1){
            //cout<<dp[n]<<endl;
            return dp[n];
        }
        if(s[0]!=0)
            left = numDecod(dp,s.substr(1));
        if(s[0] !=0 && stoi(s.substr(0,2))<=26)
            right = numDecod(dp,s.substr(2));
       
        return dp[n] = left+right;
       
    }
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1);
        dp[0]=0;
        
         int t = numDecod(dp,s);
         return dp[s.size()];
       
    }
};