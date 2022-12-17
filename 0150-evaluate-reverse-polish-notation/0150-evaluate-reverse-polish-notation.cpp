class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long>st;
      // cout<<'-2'-'0'<<endl;
        for(auto a : tokens){
            if(a != "+" && a!="-" && a != "*" && a != "/"){
                st.push(stol(a));
            }
            else{
                long  r = st.top();
                st.pop();
                long  l = st.top();
                st.pop();
                //cout<<l<<" "<<r<<endl;
                if(a=="+"){
                    st.push(l+r);
                }
                else if(a=="-"){
                    st.push(l-r);
                }
                 else if(a=="*"){
                    st.push(l*r);
                }
                else{
                    st.push(l/r);
                }
            }
        }
        return st.top();
        
    }
};