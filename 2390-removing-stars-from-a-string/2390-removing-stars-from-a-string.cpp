class Solution {
public:
    string removeStars(string s) {
        size_t found = s.find('*');
        cout<<found<<endl;
        if(found == 18446744073709551615){
            return s;
        }
        stack<char>st;
        for(auto a : s){
            if(a == '*'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(a);
            }
        }
        string ans = "";
        
        while(!st.empty()){
            ans = st.top()+ans;
            st.pop();
        }
        
        return ans;
    }
};