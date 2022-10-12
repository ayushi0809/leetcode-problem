//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          // code here 
          unordered_map<char,int>m;
          for(int i =0; i<n; i++){
              m[x[i]] = b[i];
          }
          int sum=0;
          int maxi = INT_MIN;
          string ans = "";
          string v="";
          for(int i =0; i<w.size(); i++){
              ans+=w[i];
              if(m.find(w[i]) != m.end()){
                  sum+=m[w[i]];
              }
              else{
                  sum+=int(w[i]);
              }
              if(maxi<sum){
                  maxi = sum;
                  v= ans;
              }
              if(sum<0){
                  sum =0;
                  ans="";
              }
          }
          
          return v;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends