//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
	public:
		int NthTerm(int n){
		    // Code  here
		    long long int v[n+1];
		    v[1] = 2;
		    
		    for(int i =2; i<=n; i++){
		        v[i] = ((v[i-1]*i)+1)%1000000007;
		    }
		    
		    return v[n];
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends