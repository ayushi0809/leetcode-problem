class Solution {
public:
    bool cycle(int i, vector<int> adj[], vector<bool> &visited, vector<bool> &dfsvisited, stack<int> &st){
        visited[i] = true;
        dfsvisited[i] = true;
        for(auto a : adj[i]){
            if(!visited[a]){
                if(cycle(a,adj,visited,dfsvisited,st))return true;
                   
                
            }
            else if(dfsvisited[a] == true)
                return true;
        }
        dfsvisited[i] = false;
        st.push(i);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        vector<bool>visited(numCourses+1, false);
        stack<int>st;
        for(int i =0; i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        vector<bool> dfsvisited(numCourses+1, false);
        for(int i =0; i<numCourses; i++){
            if(!visited[i]){
                if(cycle(i,adj,visited,dfsvisited,st ) == true){
                   return {};
                }
            }
        }
        vector<int>v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        return v;
        
    }
};