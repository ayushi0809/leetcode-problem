class Solution {
public:
    int maximum69Number (int num) {
        bool flag = false;
        string s = to_string(num);
        for(int i =0; i<s.size(); i++){
            if(s[i]=='6' && !flag){
                s[i] = '9';
                flag =true;
                break;
            }
        }
        //cout<<s<<endl;
        int n = stoi(s);
        return n;
        
    }
};