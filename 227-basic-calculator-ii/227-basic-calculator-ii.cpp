class Solution {
public:
    int calculate(string s) {
        stack<string>operand;
        stack<char>st;
        string res;
       // cout<<s<<endl;
        unordered_map<char,int>pre;
        pre.insert({'+',1});
        pre.insert({'-',1});
        pre.insert({'*',2});
        pre.insert({'/',2});
        int si = s.size();
        for(int i=0; i<s.size(); i++){
            //cout<<s[i]<<endl;
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                while(!st.empty() && pre[st.top()]>=pre[s[i]]){
                   long long int r = stoll(operand.top());
                    operand.pop();
                    long long int l = stoll(operand.top());
                    operand.pop();
                    char op = st.top();
                    st.pop();
                    switch(op){
                        case '+':
                            operand.push(to_string(l+r));
                            break;
                         case '-':{
                            long long int sub = l-r;
                             //cout<<sub<<endl;
                             if(sub<0){
                                 operand.push(to_string(sub));
                             }
                             else{
                            operand.push(to_string(sub));
                             }
                            break;
                         }
                        case '*':
                            operand.push(to_string(l*r));
                            break;
                        case '/':
                            operand.push(to_string(l/r));
                            break;
                            
                    }
                }
                //cout<<s[i]<<endl;
                st.push(s[i]);
            }
            else{
                while(s[i] != '+' && s[i] != '*' && s[i] != '/' && s[i] != '-' && i !=si){
                     res = res+s[i];
                    i++;
                }
               i=i-1;
                operand.push((res));
                res="";
            }
        }
        while(!st.empty()){
            long long int r = stoll(operand.top());
         //   cout<<r<<endl;
                    operand.pop();
                    long long int l = stoll(operand.top());
          //  cout<<l<<endl;
                    operand.pop();
                    char op = st.top();
           // cout<<op<<endl;
                    st.pop();
                    switch(op){
                        case '+':
                            operand.push(to_string(l+r));
                            break;
                         case '-':{
                            long long int sub = l-r;
                             cout<<to_string(sub)<<endl;
                             if(sub<0){
                                 operand.push(to_string(sub));
                             }
                             else{
                                 operand.push(to_string(sub));
                             }
                           
                            break;
                         }
                        case '*':
                            operand.push(to_string(l*r));
                            break;
                        case '/':
                            operand.push(to_string(l/r));
                            break;
                            
                    }
        }
        cout<<operand.top()<<endl;
        //long long int ev =0;
        string rev;
        while(!operand.empty()){
            rev = operand.top()+rev;
            operand.pop();
        }
         long long int ev = stoll(rev);
        return ev;
    }
};