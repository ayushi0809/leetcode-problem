class Solution {
public:
    vector<string> ans;
    void f(int n, int m, string s ){
        if(n==0 && m==0){
            ans.push_back(s);
            return;
        }
        
         if(n > 0){
         s=s+'(';
             
        f(n-1,m,s);
        s.pop_back();
        }
        if(m>n){
        s=s+')';
            
        f(n,m-1,s);
        s.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
      f(n,n,"");
        return ans;
    }
};