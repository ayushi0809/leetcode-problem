class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
      // cout<<'-2'-'0'<<endl;
        for(auto a : tokens){
            if(a != "+" && a!="-" && a != "*" && a != "/"){
                st.push(a);
            }
            else{
                int r = stoi(st.top());
                st.pop();
                int l = stoi(st.top());
                st.pop();
                //cout<<l<<" "<<r<<endl;
                if(a=="+"){
                    st.push(to_string(l+r));
                }
                else if(a=="-"){
                    st.push(to_string(l-r));
                }
                 else if(a=="*"){
                    st.push(to_string(l*r));
                }
                else{
                    st.push(to_string(l/r));
                }
            }
        }
        return stoi(st.top());
        
    }
};