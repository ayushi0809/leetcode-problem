// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
       int c=0;
      // string s;
       int q=0;
       int k =0;
       long long int s=0;
       stack<int>st;
        sort(arr, arr+n);
        for(int i= n-1; i>=0; i=i-2){
            if(i==0){
                k = c+arr[i];
            }
            else{
             k = c+arr[i]+arr[i-1];
            }
            //cout<<s<<" "<<i<<endl;
            if(i==0 || i==1)
            st.push(k);
            else{
            st.push(k%10);
            }
             c = k/10;
        }
        //cout<<s<<endl;
      
       while(!st.empty()){
           s=s*10+st.top();
           st.pop();
       }
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends