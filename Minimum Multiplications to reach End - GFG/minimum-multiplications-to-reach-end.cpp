//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
        q.push({0,start});
        //unordered_set<int>st;
        vector<int>v(100000, 1e9);
        while(!q.empty()){
            auto it = q.top();
            q.pop();
            int node = it.second;
            int l = it.first;
            if(node == end){
                return l;
            }
            for(auto it : arr){
                if(v[(it*node)%100000] > 1+l){
                    v[(it*node)%100000]= l+1;
                q.push({l+1, (it*node)%100000});
            }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends