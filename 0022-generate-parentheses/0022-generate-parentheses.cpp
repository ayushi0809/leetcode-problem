class Solution {
public:
    vector<string>ans;
    void GenPar(int l, int r, int n, string s){
        if(l==n && r==n){
           // cout<<s<<endl;
            ans.push_back(s);
            return;
        }
        if(l<n && l>=r){
           // s=s+'(';
            GenPar(l+1,r,n,s+'(');
            //cout<<s<<endl;
        }
        if(r<l){
            //s=s+')';
            GenPar(l,r+1,n,s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
     GenPar(0,0,n,"");
        return ans;
    }
};