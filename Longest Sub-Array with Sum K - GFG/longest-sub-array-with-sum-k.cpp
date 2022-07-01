// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        //vector<int>v;
        unordered_map<int,int>m;
        int mi = 0;
        int s=0;
        for(int i=0;i<N;i++){
            s=s+A[i];
           //cout<<s<<endl;
            if(s-K==0){
                mi = max(mi,i+1);
            }
            if(m.find(s-K) != m.end()){
                auto it = m.find(s-K);
                //cout<<i<<endl;
                mi = max(mi,i-it->second);
                //cout<<mi<<endl;
            }
            if(m.find(s)==m.end()){
                m[s] = i;
            }
        }
        return mi;
    } 

};

// { Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends