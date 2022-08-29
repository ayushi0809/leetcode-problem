class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream s(preorder);
        string str;
        stack<string>st;
        while(getline(s,str,',')){
        cout<<str<<endl;
            if(str != "#"){
                st.push(str);
            }
            else{
                cout<<st.empty()<<endl;
                while( !st.empty() && st.top() == "#"){
                    //cout<<st.top();
                    st.pop();
                    if(st.empty())
                        return false;
                    st.pop();
                    //st.push("#");
                    
                }
                
                   st.push("#");
                
            }
        }
        
        if(st.size() == 1 && st.top()== "#")
            return true;
        // cout<<st.size()<<endl;
        // cout<<st.top()<<endl;
        return false;
    }
};