class Solution {
public:
    vector<vector<int>>ans;
    void f(int i, int n, vector<int>v, int k){
       
        if(k==0){
            ans.push_back(v);
            return;
        }
        
        //f(i+1,n,v,k);
        
        for(int j =i; j<=n; j++){
            v.push_back(j);
            f(j+1,n,v,k-1);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        f(1,n,{},k);
        
        return ans;
    }
};