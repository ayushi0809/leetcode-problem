class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int i , vector<int>v, int n, vector<vector<int>>& graph){
        if(i==n-1){
            v.push_back(i);
            ans.push_back(v);
            return;
        }
        v.push_back(i);
        for(auto a : graph[i]){
            dfs(a,v,n,graph);
           
        }
         v.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>v;
        dfs(0,v,n,graph);
        return ans;
    }
};