//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int *tree;
    void buildTree(int tree[], int a[], int start, int end, int currNode){
        if(start == end){
            tree[currNode] = a[start];
            return;
        }
        int mid = (start+end)/2;
        buildTree(tree, a, start, mid, 2*currNode+1);
        buildTree(tree,a,mid+1,end, 2*currNode+2);
        
        tree[currNode] = tree[2*currNode+1]^tree[2*currNode+2];
        
    }
    int QueryXOR(int tree[], int start, int end, int left, int right, int currNode){
        if(left>end || right < start)
            return 0;
        
        if(left<=start && right >= end ){
            return tree[currNode];
        }
        
        int mid = (start+end)/2;
        
        int l = QueryXOR(tree,start,mid,left,right,2*currNode+1);
        int r = QueryXOR(tree,mid+1,end,left,right,2*currNode+2);
        
        
        return l^r;
    }
    vector<int> specialXor(int N, int Q, int a[], vector<int> query[])
    {
        // code here
        tree = new int[4*N];
        buildTree(tree,a,0,N-1,0);
        int total_XOR = tree[0];
        vector<int>ans;
        for(int i =0; i<Q; i++){
            auto it = query[i];
            int res = QueryXOR(tree,0,N-1, it[0]-1, it[1]-1, 0);
            ans.push_back(total_XOR^res);
        }
        
        return ans;
    }
}; 

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, Q;
        cin>>N>>Q;
        int a[N];
        for(int i = 0;i < N;i++)
            cin>>a[i];
        int l, r;
        vector<int> query[Q];
        for(int i = 0;i < Q;i++){
            cin>>l>>r;
            query[i].push_back(l);
            query[i].push_back(r);
        }
        
        Solution ob;
        vector<int> ans = ob.specialXor(N, Q, a, query);
        for(int u: ans)
            cout<<u<<"\n";
    }
    return 0;
}
// } Driver Code Ends