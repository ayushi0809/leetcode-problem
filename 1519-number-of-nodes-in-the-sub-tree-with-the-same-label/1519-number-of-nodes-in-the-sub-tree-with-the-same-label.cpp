class Solution {
public:
    vector<int> dfs(int curr, int parent, vector<int>adj[], string &labels, vector<int> &ans ){
        if(adj[curr].size()==0){
            char ch = labels[curr];
            vector<int>v(26,0);
            v[ch-'a']++;
            ans[curr] = 1;
            return v;
        }
        vector<int>v1(26,0);
       for(auto it : adj[curr]){
           if(it != parent){
               auto freq =dfs(it,curr,adj,labels,ans);
               //cout<<it<<" "<<curr<<endl;
               for(int i =0; i<26; i++){
                   v1[i] = v1[i]+freq[i];
               }
               
           }
       }
        
        ans[curr] = ++v1[labels[curr]-'a'];
        return v1;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int>adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>ans(n,1);
       // vector<bool>vis(n,false);
        vector<int>count(26,0);
        dfs(0,-1,adj,labels,ans);
        
        return ans;
        
    }
};