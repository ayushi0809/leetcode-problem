class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = s.size()-2;
        while(i>=0 && s[i]>=s[i+1]){
            i--;
        }
        cout<<i<<endl;
        if(i<0){
            reverse(s.begin(), s.end());
        }
        else{
        int n = s.size()-1;
        while(n>=0){
            if(s[n]>s[i]){
                break;
            }
            n--;
        }
        
        swap(s[i], s[n]);
        reverse(s.begin()+1+i, s.end());
        }
        int ans = stoll(s);
        if(ans<=n){
            return -1;
        }
        return ans;
    }
};