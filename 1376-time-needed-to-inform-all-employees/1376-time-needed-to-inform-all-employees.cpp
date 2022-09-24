class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<int>adj[n];
        
        for(int i =0; i<n; i++){
            if(manager[i] != -1){
            adj[manager[i]].push_back(i);
            }
        }
        queue<pair<int,int>>q;
        q.push({headID, informTime[headID]});
        int ans =0;
        int time;
        while(!q.empty()){
            int h = q.front().first;
             time = q.front().second;
            q.pop();
            ans = max(ans,time);
            for(auto a : adj[h]){
                
                q.push({a, time+informTime[a]});
                
            }
            
        }
        
        return ans;
    }
};