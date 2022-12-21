class Solution {
public:
    bool dfs(int node, int c, vector<int>adj[], vector<int>&color){
        color[node] = c;

        for(auto a : adj[node]){
            if(color[a] == -1){
                if(!dfs(a,abs(c-1),adj,color))return false;
            }

            else if(color[a] == c){
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];

        for(int i =0; i<dislikes.size(); i++){
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>color(n+1,-1);
        // queue<pair<int,int>>q;
        for(int i =1; i<=n; i++){
            if(color[i] == -1){
                if(dfs(i,0,adj,color)==false)return false;
            }
        }
        return true;
        // q.push({1,0});
        // for(int i =1; i<=n; i++){
        //     if(color[i] == -1){
        //         color[i] = 0;
        //         q.push({i,0});
        //     }
        
        // while(!q.empty()){
        //     auto it = q.front();
        //     //cout<<it.first<<endl;
        //     q.pop();

        //     for(auto a : adj[it.first]){
        //         if(color[a] == -1){
        //             color[a] = abs(it.second-1);
        //             q.push({a,abs(it.second-1)});
        //         }
        //         else if(color[a]==it.second){
        //             return false;
        //         }
        //     }
        // }
        // }

        // return true;
    }
};