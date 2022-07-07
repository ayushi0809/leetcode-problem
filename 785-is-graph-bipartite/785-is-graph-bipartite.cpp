class Solution {
public:
    bool f(int i, vector<vector<int>>& graph, vector<int> &color ){
        queue<int>q;
        color[i] =1;
        q.push(i);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto a: graph[x]){
                if(color[a] == -1){
                    color[a] = 1-color[x];
                    q.push(a);
                }
                else if(color[a] == color[x]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        bool t = true;
        vector<int>color(n, -1);
        for(int i =0; i<n; i++){
            if(color[i] ==-1){
                 t = t &&f(i,graph,color);
                cout<<t<<endl;
            }
        }
        return t;
    }
};