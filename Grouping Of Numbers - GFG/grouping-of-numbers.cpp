//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int arr[], int N, int K) {
        // code here
        vector<int>v(K, 0);
        
        for(int i =0; i<N; i++){
            v[arr[i]%K]++;
        }
        
        int l =1;
        int r = K-1;
        int count =0;
        while(l<r){
           count = count+max(v[l], v[r]);
           l++;
           r--;
        }
        if(v[0]>0){
            count++;
        }
        if(K%2==0){
            int mid = K/2;
            if(v[mid]>0){
                count++;
            }
        }
        // else{
        //     int mid = (K/2);
        //     cout<<mid<<endl;
        //     count=count+v[mid];
        // }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends