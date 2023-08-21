class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i =1; i<=n/2; i++){
            
            // cout<<len<<" "<<substr<<endl;
            if(n%i==0){
            string newstr = "";
           for(int j =0; j<n/i; j++){
               newstr = newstr+s.substr(0,i);
           }
            // cout<<newstr<<endl;
            if(newstr == s){
                return true;
            }
            }
        }
        return false;
        
    }
};