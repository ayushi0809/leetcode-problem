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
        if(s[0]== '0'){
            return 0;
        }
        if(s.size() == 1 && s[0] != '0'){
            return 1;
        }
        vector<int> dp(s.size()+1,0);
        int n = s.size();
        dp[0]=0;
        if(s[n-1] !='0'){
            dp[1] = 1;
        }
        string str = "";
            str = str+s[n-2]+s[n-1];
       // cout<<str<<endl;
        if(stoi(str)<=26){
            cout<<str[0]<<endl;
            if(str[0] == '0' && str[1] == '0'){
                dp[2]=0;
            }
            if(str[0] !='0' && str[1]=='0'){
                dp[2] =1;
            }
            if(str[0] =='0'){
                dp[2] =0;
            }
            if(str[0] !='0' && str[1] != '0'){
                dp[2] =2;
            }
            
            
        }
        
        else{
             if(str[0] !='0' && str[1] != '0'){
                dp[2] =1;
            }
            else{
                dp[2] =0;
            }
            
        }
        
        for(int i =3;i<=n; i++){
            string st = "";
               st = st+s[n-i]+s[n-i+1];
            //cout<<st<<endl;
           if(s[n-i]== '0')
               dp[i]=0;
            else if(stoi(st)<=26){
                //cout<<dp[i-1]<<" "<<dp[i-2]<<endl;
                dp[i] = dp[i-1]+dp[i-2];
            }
            else{
                dp[i] = dp[i-1];
            }
            
        }
        
         return dp[n];
       
    }
};