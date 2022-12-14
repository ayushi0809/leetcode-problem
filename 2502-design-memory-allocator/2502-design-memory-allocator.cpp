class Allocator {
public:
    unordered_map<int,vector<int>>m;
    vector<int>v;
    int s;
    int index;
    Allocator(int n) {
        v.resize(n,0);
        s=n;
        index=0;
    }
    
    int allocate(int size, int mid) {
        if(size>s){
            return -1;
        }
        int start = 0;
        int end =0;
        int i =0;
        bool flag = false;
        // if(size==1){
        //     while(i<s){
        //         //cout<<i<<" "<<v[i]<<endl;
        //         if(v[i]==0){
        //            // cout<<i<<" "<<v[i]<<endl;
        //             v[i]=mid;
        //             m[mid].push_back(i);
        //             return i;
        //         }
        //         i++;
        //     }
        // }
       while(end<s){
           if(end-start==size){
               for(int j = start; j<end; j++){
                   v[j]=mid;
                   m[mid].push_back(j);
               }
               return start;
           }
           if(v[end]!=0){
               if(end-start != size){
                   start = end+1;
               }
           }
           
           
           end++;
       }
        if(end-start==size){
               for(int j = start; j<end; j++){
                   v[j]=mid;
                   m[mid].push_back(j);
               }
               return start;
           }
        
        return -1;
        
    }
    
    int free(int mid) {
        if(m.find(mid)==m.end()){
            return 0;
        }
        int res = m[mid].size();
        int j = 0;
        vector<int>temp = m[mid];
        while(j<res){
           v[temp[j]]=0;
            j++;
        }
        m.erase(mid);
        return res;
        
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */