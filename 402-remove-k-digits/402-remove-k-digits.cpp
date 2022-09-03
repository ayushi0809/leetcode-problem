class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        int K = k;
        if(k==n)
            return "0";
        stack<char>st;
        //cout<<'1'-'0'<<endl;
        for(auto a : num){
            while(!st.empty() && k>0 && st.top() - '0' > a-'0'){
                 st.pop();
                k--;     
        }
            if(st.empty() && a=='0'){
                continue;
            }
           else{
                st.push(a);
           }
          
        }
         string ans = "";
        //cout<<st.size()<<endl;
       
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
       //bool flag = true;
         if(st.empty()){
            return "0";
        }
        while(!st.empty()){
                num[n-1] = st.top();
                n--;
                st.pop();
            
        }
       
        
        return num.substr(n);
        
    }
};