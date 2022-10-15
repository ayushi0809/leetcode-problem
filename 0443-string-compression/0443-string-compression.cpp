class Solution {
public:
    int compress(vector<char>& chars) {
       vector<char>s;
        int start =0;
        int end = 1;
        char ch = chars[start];
        int n = chars.size();
        if(n==1){
            return 1;
        }
        // char t = 1+'0';
        //     cout<<t<<endl;
        while(end<n){
            if(ch != chars[end]){
                int len = end-start;
                if(len==1){
                    s.push_back(ch);
                }
                else if(len<=9){
                    s.push_back(ch);
                    s.push_back(len+'0');
                }
                else{
                    string a = to_string(len);
                    s.push_back(ch);
                    int j =0;
                    while(j<a.size()){
                        s.push_back(a[j]);
                        j++;
                    }
                }
                
                start = end;
                
            }
            ch = chars[end];
            end++;
        }
        //cout<<chars[end]<<endl;
                int len = end-start;
                if(len==1){
                    s.push_back(ch);
                }
                else if(len<=9){
                    s.push_back(ch);
                    s.push_back(len+'0');
                }
                else{
                    string a = to_string(len);
                    s.push_back(ch);
                    int j =0;
                    while(j<a.size()){
                        s.push_back(a[j]);
                        j++;
                    }
                }
        
        chars = s;
       // cout<<s.size()<<endl;
        return chars.size();
    }
};