class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        if(n==0)
            return 0;
        stack<char>st;
        int ans=0;
        for(auto a : s){
            if(a== '('){
                //opening++;
                st.push('(');
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
                else{
                ans++;
                }
            }
        }
        //return abs(opening-closing);
        ans = ans+st.size();
        
        return ans;
    }
};