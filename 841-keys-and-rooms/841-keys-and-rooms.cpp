class Solution {
public:
    void dfs(int i, vector<vector<int>>& rooms, vector<bool>&visited ){
        visited[i] = true;
        for(auto a : rooms[i]){
            if(!visited[a]){
                dfs(a, rooms, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n, false);
        
        int count =0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                count++;
                dfs(i,rooms, visited);
            }
        }
        if(count>1)
            return false;
        else
            return true;
    }
};