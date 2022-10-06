class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        
        
        queue<pair<pair<int,int>, int>>q;
        
        q.push({{entrance[0] , entrance[1]},0});
        
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        vis[entrance[0]][entrance[1]] = true;
        
        int count =INT_MAX;
        vector<int>delta = {0,1,0,-1,0};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
           
            int r = it.first.first;
            int c = it.first.second;
            int level = it.second;
             cout<<r<<" "<<c<<endl;
             if(r != entrance[0] || c != entrance[1]){
            if(r== 0 || r== n-1 || c==0 || c== m-1){
                //cout<<r<<" "<<c<<endl;
                count = min(count, level);   
            } 
                }
            
            
            for(int i =0; i<4; i++){
                int row = r+delta[i];
                int col = c+delta[i+1];
                
                if(row>=0 && row<n && col>=0 && col<m && vis[row][col] == false && maze[row][col] == '.'){
                    vis[row][col] = true;
                    q.push({{row,col}, level+1});
                }
            }
            
        }
        if(count == INT_MAX){
            return -1;
        }
        return count;
        
    }
};