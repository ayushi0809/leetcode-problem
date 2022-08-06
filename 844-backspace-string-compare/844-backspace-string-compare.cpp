class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>ss;
        stack<char>st;
        for(int i =0; i<s.size();i++){
            if(s[i] == '#'){
                if(ss.empty()==false){
                    ss.pop();
                }
            }
            else{
                ss.push(s[i]);
            }
        }
         for(int i =0; i<t.size();i++){
            if(t[i] == '#'){
                if(st.empty()==false){
                    st.pop();
                }
            }
            else{
                st.push(t[i]);
            }
        }
        while(ss.empty()==false && st.empty()==false){
            if(ss.top()==st.top()){
                ss.pop();
                st.pop();
            }
            
            else
                return false;
        }
        if(ss.empty()&&st.empty())
            return true;
        return false;
    }
};