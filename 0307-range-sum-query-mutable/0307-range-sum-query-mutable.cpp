class NumArray {
public:
    vector<int>v;
    int n;
    int *tree;
    void build(vector<int> &v, int tree[], int start, int end, int currNode){
        if(start==end){
            tree[currNode] = v[start];
            return ;
        }
        int mid = (start+end)/2;
        build(v,tree,start,mid,2*currNode+1);
        build(v,tree,mid+1,end,2*currNode+2);
        
        tree[currNode] = tree[2*currNode+1]+tree[2*currNode+2];
    }
    int QuerySum(int tree[],int start, int end, int left, int right, int currNode){
        int mid = (start+end)/2;
        if(left>end){
            return 0;
        }
        if(right<start){
            return 0;
        }
        if(left<=start && right>=end){
            return tree[currNode];
        }
        return QuerySum(tree,start,mid,left,right,2*currNode+1)+QuerySum(tree,mid+1,end,left,right,2*currNode+2);
        
    }
    void UpdateInd(int tree[],int start,int end, int index, int val, int currNode){
        int mid = (start+end)/2;
        if(start == end && start == index){
            tree[currNode] = val;
            return ;
        }
        if(mid<index){
            UpdateInd(tree,mid+1,end,index,val,2*currNode+2);
        }
        
        if(mid>=index){
            UpdateInd(tree,start,mid,index,val,2*currNode+1);
        }
        tree[currNode] = tree[2*currNode+1]+tree[2*currNode+2];
    }
    NumArray(vector<int>& nums) {
        v=nums;
        n =nums.size();
        tree = new int[4*n];
        build(nums,tree,0,n-1,0);
    }
    
    void update(int index, int val) {
        UpdateInd(tree,0,n-1,index,val,0);
    }
    
    int sumRange(int left, int right) {
       // return 0;
        
        return QuerySum(tree,0,n-1,left,right,0);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */