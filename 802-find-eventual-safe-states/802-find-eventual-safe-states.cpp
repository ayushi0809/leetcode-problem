class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>outdegree(n);
        vector<int>adj[n];
        for(int i=0; i<n; i++){
            for(auto a : graph[i]){
                outdegree[i]++;
                adj[a].push_back(i);
            }
        }
        queue<int>q;
        for(int i=0; i<n; i++){
            if(outdegree[i]==0){
                q.push(i);
            }
        }
        vector<int>v;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            v.push_back(x);
            for(auto a : adj[x]){
                outdegree[a]--;
                if(outdegree[a]==0){
                    q.push(a);
                }
            }
        }
        sort(v.begin(), v.end());
        return v;
    }
};