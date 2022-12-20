class Solution {
public:
    void dfs(int i, vector<vector<int>>& rooms, vector<bool>&vis){
        vis[i] = true;
        for(auto a : rooms[i]){
            if(!vis[a]){
                dfs(a,rooms,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>vis(n,false);
        int count =0;
        for(int i =0; i<rooms.size(); i++){
            if(!vis[i]){
                count++;
                dfs(i,rooms,vis);
            }
        }
        if(count==1)
            return true;
        return false;
    }
};