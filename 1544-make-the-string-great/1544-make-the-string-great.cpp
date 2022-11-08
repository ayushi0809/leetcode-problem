class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        int n = s.size();
        int i =0;
        while(i<n){
            while(!st.empty() && ((islower(st.top()) && toupper(st.top()) == s[i] )  || (isupper(st.top()) && tolower(st.top()) == s[i]))){
                st.pop();
                i++;
            }
            if(i<n){
            st.push(s[i]);
            }
            //cout<<s[i]<<"hkh"<<i<<endl;
            i++;
        }
        string ans = "";
        while(!st.empty()){
            //cout<<st.top()<<endl;
           
           ans= st.top()+ans;
            
            st.pop();
        }
        
        return ans;
        
    }
};