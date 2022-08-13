class Solution {
public:
//    gives tle  
    //vector<string>ans;
//     void f(int n, string v, string s){
//         if(v.size()==n){
//            ans.push_back(v);
//             return;
//         }
//         for(int i = 0; i<n; i++){
            
//             if(s[i] != '$'){
//                 char j = s[i];
//                 v=v+s[i];
//                 s[i] = '$';
//                 f(n,v,s);
//                 s[i] = j;
//                 v.pop_back();
//             }
//         }
//     }
    string getPermutation(int n, int k) {
        string s = "";
        int fact = 1;
        for(int i =1; i<=n;i++){
            fact = fact*i;
            s=s+char(i+'0');
        }
        k--;
        string ans = "";
        cout<<fact<<endl;
        while(s.size()>0){
            fact = fact/s.size();
            ans = ans+s[k/fact];
            s.erase(s.begin()+k/fact);
            
            k = k%fact;
            //fact = fact/s.size();
        }
        
        return ans;
        // f(n,"",s);
        // sort(ans.begin(), ans.end());
        // return ans[k-1];
       // return s;
    }
};