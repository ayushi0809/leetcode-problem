// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


void printPostOrder(int in[], int pre[], int n);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int pre[N],in[N];
        for(int i=0;i<N;i++)
            cin>>in[i];
        for(int i=0;i<N;i++)
            cin>>pre[i];
        printPostOrder(in,pre,N);
        cout<<endl;

    }
}
// } Driver Code Ends


/*prints the post order traversal of the 
tree */
int index(int in[], int p, int n){
    for(int i =0; i<n; i++){
        if(in[i]==p){
            return i;
        }
       
    }
     return -1;
}
void printPostOrder(int in[], int pre[], int n)
{
//Your code here
int root = index(in, pre[0], n);
if(root !=0){
    printPostOrder(in, pre+1, root);
}
if(root != n-1){
    printPostOrder(in+root+1, pre+root+1,n-root-1);
}
cout<<pre[0]<<" ";
}