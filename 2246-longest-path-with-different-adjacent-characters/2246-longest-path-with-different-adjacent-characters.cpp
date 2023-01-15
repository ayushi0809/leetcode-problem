class Solution {
public:
    int maxchain = INT_MIN;
    int dfs(int curr, int parent, vector<int>adj[], string &s){
        int longestchain = 0;
        int secondlongestchain = 0;
        for(auto it : adj[curr]){
            int ht = dfs(it,curr,adj,s);
            if(s[it] == s[curr]){
                continue;
            }
            if(ht>longestchain){
                secondlongestchain = longestchain;
                longestchain = ht;
            }
            else if(ht>secondlongestchain){
                secondlongestchain = ht;
                
            }
        }
        
        maxchain  = max(maxchain, longestchain+secondlongestchain+1);
        
        return longestchain+1;
        
        
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int>adj[n];
        for(int i =0; i<parent.size(); i++){
            if(parent[i] != -1){
                //adj[i].push_back(parent[i]);
                adj[parent[i]].push_back(i);
            }
        }
        
        dfs(0,-1,adj,s);
        
        return maxchain;
        
        
    }
};