class Solution {
public:
    string breakPalindrome(string &palindrome) {
        int n = palindrome.size();
        if(n==1)
            return "";
        bool check = false;
        string s = palindrome;
        for(int i =0; i<n/2; i++){
            if(s[i]!='a'){
                s[i]='a';
                check = true;
                break;
            }
        }
        if(!check){
                s[n-1] = 'b';
            
        }
        
        return s;
    }
};