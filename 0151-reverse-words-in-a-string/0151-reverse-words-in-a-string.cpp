class Solution {
public:
    string reverseWords(string s) {
        string x = "";
        string t = "";
        //cout<<s.size()<<endl;
        for(int i =0; i<s.size(); i++){
        //cout<<i<<endl;
           // cout<<x<<endl;
            if(s[i] == ' ' ){
                if(x != "" ){
                    //cout<<i<<endl;
                t = x+t;
                t = ' '+t;
                x="";
                }
            }
            else{
                x = x+s[i];
            }
        }
        t =x+t;
        if(t[0] == ' '){
            return t.substr(1);
        }
        return t;
        
    }
};