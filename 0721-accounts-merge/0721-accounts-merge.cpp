class Disjointset{
    vector<int>rank, parent, size;
    int n;
    
    public:
    Disjointset(int v){
        n=v;
        rank.resize(v+1, 0);
        parent.resize(v+1);
        size.resize(v+1);
        for(int i =0; i<n; i++){
            parent[i] = i;
        }
        
        for(int i =0; i<n; i++){
            size[i] = 1;
        }
        
    }
    
    int findpar(int u){
        if(u==parent[u])
            return u;
        return parent[u] = findpar(parent[u]);
    }
    
    void unionbyrank(int u, int v){
        int ult_pu = findpar(u);
        int ult_pv = findpar(v);
        if(ult_pu == ult_pv)
            return;
        if(rank[ult_pu] < rank[ult_pv]){
            parent[ult_pu] = ult_pv;
        }
        else if(rank[ult_pv] < rank[ult_pu]){
            parent[ult_pv] = ult_pu;
        }
        else{
            parent[ult_pu] = ult_pv;
            rank[ult_pv]++;
        }
    }
    
    void unionbysize(int u, int v){
         int ult_pu = findpar(u);
        int ult_pv = findpar(v);
        if(ult_pu == ult_pv)
            return;
        if(size[ult_pu] < size[ult_pv]){
            parent[ult_pu] = ult_pv;
            size[ult_pv] +=size[ult_pu];
        }
        else{
             parent[ult_pv] = ult_pu;
            size[ult_pu] +=size[ult_pv];
        }
        
    }
    int count(){
        int count =0;
       for(int i =1; i<=n; i++){
           if(parent[i] == i)
               count++;
       }
       
        return count;
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        Disjointset ds(n);
        vector<vector<string>>ans;
        vector<vector<string>>mail(n);
        unordered_map<string,int>m;
        
        for(int i =0; i<n; i++){
            for(int j =1; j<accounts[i].size(); j++){
                if(m.find(accounts[i][j])  == m.end()){
                    m[accounts[i][j]] = i;
                }
                else{
                    ds.unionbysize(m[accounts[i][j]], i);
                }
            }
        }
        
        for(auto it = m.begin(); it != m.end(); it++){
            int p = ds.findpar(it->second);
            mail[p].push_back(it->first);
        }
        
        for(int i =0; i<n; i++){
            auto it = mail[i];
            if(it.size()>0){
                sort(it.begin(), it.end());
                it.insert(it.begin() , accounts[i][0]);
                ans.push_back(it);
            }
        }
        
        return ans;
        
    }
};