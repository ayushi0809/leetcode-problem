class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int>adj[numCourses];
        vector<int>indegree(numCourses,0);
        int e = prerequisites.size();
        for(int i=0; i<e; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
            indegree[v]++;
            
        }
        queue<int>q;
        vector<vector<bool>>isreachable(numCourses, vector<bool>(numCourses, false));
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int s = q.size();
            while(s){
                int node = q.front();
                q.pop();
                for(auto a : adj[node]){
                    isreachable[node][a] =true;
                    indegree[a]--;
                    if(indegree[a]==0)
                        q.push(a);
                
                for(int i =0; i<numCourses; i++){
                    if(isreachable[i][node]){
                        isreachable[i][a] = true;
                    }
                }
                }
                s--;
            }
        }
        vector<bool>v;
        for(auto it : queries){
            v.push_back(isreachable[it[0]][it[1]]);
        }
        return v;
        
    }
};