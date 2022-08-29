class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int>v;
        stack<int>st;
        for(int i =0; i<=s.size(); i++){
            st.push(i);
            if(i == s.size() || s[i] == 'I'){
                while(!st.empty()){
                    v.push_back(st.top());
                    st.pop();
                }
            }
        }
        return v;
    }
};