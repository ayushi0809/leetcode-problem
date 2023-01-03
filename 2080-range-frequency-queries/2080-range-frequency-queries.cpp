class RangeFreqQuery {
public:
    unordered_map<int,vector<int>> tree;
//     int n;
//     void buildTree( vector<int> &arr, int start, int end, int currNode){
//         if(start==end){
//             tree[currNode].insert({arr[start],1});
//             return;
//         }
        
//         int mid = (start+end)/2;
        
//         buildTree(arr,start,mid,2*currNode+1);
//         buildTree(arr,mid+1,end,2*currNode+2);
        
//         unordered_map<int,int> map1 = tree[2*currNode+1];
//         unordered_map<int,int> map2 = tree[2*currNode+2];
        
//         unordered_map<int,int>m;
        
//         for(auto &it : map1){
//                 m[it.first] = it.second;         
//         }
        
//         for(auto &it : map2){
//             m[it.first] = m[it.first]+it.second;
//         }
        
//         tree[currNode] = m;
        
//     }
//     int QueryFreq( int start, int end, int left,int right,int val, int currNode){
//         if(left>end || right <start){
//             return 0;
//         }
//         if(left<=start && right>=end){
//             auto it = tree[currNode];
//             return it[val];
//         }
        
//         int mid = (start+end)/2;
        
//          int l = QueryFreq(start,mid,left,right,val,2*currNode+1);
//          int r = QueryFreq(mid+1,end,left,right,val,2*currNode+2);
        
//         return l+r;
        
//     }
    RangeFreqQuery(vector<int>& arr) {
         int n = arr.size();
        for(int i =0; i<n; i++){
            tree[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        //return QueryFreq(0,n-1,left,right,value,0);
        if(tree[value].size()==0)
            return 0;
        if(tree.size()==1){
            return right-left+1;
        }
        
        vector<int>temp = tree[value];
        int lb = lower_bound(temp.begin(), temp.end(), left)-temp.begin();
        int ub = upper_bound(temp.begin(),temp.end(),right)-temp.begin();
        
        
        return ub-lb;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */