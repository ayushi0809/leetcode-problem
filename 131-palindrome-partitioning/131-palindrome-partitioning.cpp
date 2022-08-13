class Solution {
public:
    vector<vector<string>>ans;
    bool ispallindrome(string s1, int s, int e){
        while(s<=e){
            if(s1[s] != s1[e]){
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
    
    void f(int ind, int n , string s, vector<string>v){
        if(ind==n){
            ans.push_back(v);
            return;
        }
        
        for(int i = ind; i<n; i++){
           
            if(ispallindrome(s,ind,i)){
                // cout<<ispallindrome(s,ind,i)<<" "<<i<< " "<<ind<<endl;
                v.push_back(s.substr(ind, i-ind+1));
                f(i+1,n,s,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        f(0,n,s,{});
        
        return ans;
        
        
    }
};