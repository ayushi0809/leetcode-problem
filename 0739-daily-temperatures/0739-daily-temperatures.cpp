class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
       
        int n = temperatures.size();
         vector<int>v(n);
        for(int i =n-1; i>=0; i--){
            //cout<<i<<endl;
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]){
                st.pop();
            }
            if(st.empty()){
                v[i] =0;
            }
            else{
                v[i] = st.top()-i;
            }
            st.push(i);
        }
        return v;
    }
};