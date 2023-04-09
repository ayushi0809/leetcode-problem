class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int>adj[n];
        vector<int>indegree(n,0);
        vector<vector<int>>count(n,vector<int>(26,0));
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        int answer =0;
        int nodesSeen =0;
        for(int i =0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            answer = max(answer, ++count[it][colors[it]-'a']);
            nodesSeen++;
            for(auto a : adj[it]){
                for(int i =0; i<26; i++){
                    count[a][i] = max(count[a][i], count[it][i]);
                }
                indegree[a]--;
                if(indegree[a]==0){
                    q.push(a);
                }
            }
        }
        if(nodesSeen != n){
            return -1;
        }
        
        return answer;
        
    }
};