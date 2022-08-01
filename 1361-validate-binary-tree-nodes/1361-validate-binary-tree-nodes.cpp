class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>adj[n];
        int edges=0;
        vector<int>indegree(n);
        for(int i=0; i<n; i++){
            if(leftChild[i] != -1){
                adj[i].push_back(leftChild[i]);
                indegree[leftChild[i]]++;
                edges++;
            }
            if(rightChild[i] != -1){
                adj[i].push_back(rightChild[i]);
                indegree[rightChild[i]]++;
                edges++;
            }
        }
        queue<int>q;
        for(int i=0; i<n; i++){
            if(indegree[i]>1)
                return false;
        
        if(indegree[i]==0){
            q.push(i);
        }
        }
        int count =0;
        while(!q.empty()){
            int s = q.size();
            while(s){
                int node = q.front();
                count++;
                q.pop();
                for(auto a : adj[node]){
                    indegree[a]--;
                    if(indegree[a]==0)
                        q.push(a);
                }
                s--;
            }
        }
        cout<<count<<" "<<edges<<endl;
        if(count != n || edges != n-1)
            return false;
        return true;
    }
};