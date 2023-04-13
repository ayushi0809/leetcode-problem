class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int ind =0;
        for(auto it : pushed){
            st.push(it);
            while(!st.empty() && st.top() == popped[ind]){
                st.pop();
                ind++;
            }
        }
        
        return st.empty();
        
    }
};