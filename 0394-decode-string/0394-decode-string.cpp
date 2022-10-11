class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        string ans ="";
        stack<char>st;
        for(int i =0; i<n; i++){
            string temp = "";
            string num ="";
            string s1 ="";
            if(s[i] == ']'){
            while(!st.empty() && st.top() != '['){
                temp = st.top()+temp;
                st.pop();
            }
                
            st.pop();
                //cout<<st.top()<<endl;
            while(!st.empty() && !isalpha(st.top()) && st.top() != '['){
                num = st.top()+num;
                st.pop();
            }
                cout<<num<<endl;
            for(int j =0; j<stoi(num); j++){
                s1 = s1+temp;
            }
            for(auto a: s1){
                st.push(a);
            }
            }
            else{
            st.push(s[i]);
            }
            
            
        }
        while(!st.empty()){
         ans = st.top()+ans;   
             st.pop();
        }
       return ans;
    }
};