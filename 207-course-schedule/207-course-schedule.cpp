class Solution {
public:
    // bool cycle(int i, vector<bool> &visited, vector<int>adj[]){
    //     queue<pair<int,int>>q;
    //     q.push({i,-1});
    //     visited[i] = true;
    //     while(!q.empty()){
    //         int v = q.front().first;
    //         int prev = q.front().second;
    //         q.pop();
    //         for(auto a: adj[v]){
    //             if(!visited[a]){
    //                 visited[a] =true;
    //                 q.push({a,v});
    //             }
    //             else if( prev !=  a){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }
    bool cycle(int i, vector<int> adj[], vector<bool> &visited, vector<bool> &dfsvisited){
        visited[i] = true;
        dfsvisited[i] = true;
        for(auto a : adj[i]){
            if(!visited[a]){
                if(cycle(a,adj,visited,dfsvisited))return true;
                   
                
            }
            else if(dfsvisited[a] == true)
                return true;
        }
        dfsvisited[i] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()<1)
            return true;
        vector<int> adj[numCourses];
        for(int i =0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
            //adj[u].push_back(v);
        }
    //     for(int i =0; i<numCourses; i++){
    //     cout<< i<< "->";
    //     for(int j =0; j<adj[i].size(); j++){
    //         if(j != adj[i].size()-1){
    //         cout<<adj[i][j]<<"->";
    //         }
    //         else{
    //             cout<<adj[i][j];
    //         }
    //     }
    //     cout<<endl;
    // }
        vector<bool> visited(numCourses+1, false);
        vector<bool> dfsvisited(numCourses+1, false);
        for(int i =0; i<numCourses; i++){
            if(!visited[i]){
                if(cycle(i,adj,visited,dfsvisited ) == true){
                   cout<< cycle(i,adj,visited,dfsvisited)<<endl;
                    return false;
                }
            }
        }
        return true;
    }
};