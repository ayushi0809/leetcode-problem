class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        if(columnNumber<=26){
            ans = ans+(char)(65+columnNumber-1);
        }
       while(columnNumber > 26){
           int q = columnNumber/26;
           int rem = columnNumber%26;
          
           if(rem ==0 ){
               ans = 'Z'+ans;
               q=q-1;
               // cout<<ans<<" "<<q<<endl;
           }
           else{
           ans = (char)(65+rem-1)+ans;
           }
           if(q<=26){
               // cout<<q<<" "<<ans<<endl;
               ans = (char)(65+q-1)+ans;
           }
            columnNumber = q;
           
       }
        
        return ans;
        
    }
};