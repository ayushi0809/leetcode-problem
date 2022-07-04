// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    unordered_map<char,int>m;
    int start =0;
    int count =0;
    int mi = -1;
    for(int i =0;i<s.size();i++){
        m[s[i]]++;
        count++;
        if(m.size()==k){
            mi = max(mi,count);
            
            
        }
        //cout<<mi<<endl;
        //cout<<m.size()<<endl;
        if(m.size()>k){
            m[s[start]]--;
            count--;
            if(m[s[start]] == 0){
                //cout<<s[start]<<endl;
                m.erase(s[start]);
                
                //cout<<m.size()<<endl;
            }
            start++;
        }
    }
    return mi;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends