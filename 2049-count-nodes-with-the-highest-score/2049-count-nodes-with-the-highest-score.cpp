class Solution {
public:
    int count =0;
    int dfs(vector<int>adj[], int i, vector<int>&size){
        int ans =1;
       
        for(auto a : adj[i]){
            ans = ans+dfs(adj,a,size);
           
        }
        return size[i] = ans;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<int>adj[n];
        
        for(int i =1; i<n; i++){
            adj[parents[i]].push_back(i);
        }
        vector<int>size(n);
        vector<long>v(n);
        dfs(adj,0,size);
       
        long maxi = LONG_MIN;
        
        for(int i =0; i<n; i++){
            long mul =1;
            for(auto a : adj[i]){
                mul = mul*size[a];
            }
            if(size[i] != n){
                maxi = max(maxi, mul*(n-size[i]));
                v[i] = mul*(n-size[i]);
            }
            else{
                maxi = max(maxi,mul);
                v[i] = mul;
            }
            
        }
       for(auto a : v){
           if(a==maxi){
               count++;
           }
       }
        return count;
    }
};