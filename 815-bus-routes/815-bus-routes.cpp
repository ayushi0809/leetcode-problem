class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        int m = routes[0].size();
        unordered_map<int,vector<int>>mp;
        
        for(int i =0; i<n; i++){
            for(auto a : routes[i]){
                //cout<<routes[i][j]<<endl;
                mp[a].push_back(i);
            }
        }
        vector<bool>bus(n,false);
        //no. of bus stop
        // int x = mp.size();
        // cout<<x<<endl;
        //vector<bool>busstop(x,false);
        unordered_map<int,bool>busstop;
        queue<pair<int,int>>pq;
        pq.push({source,0});
        busstop[source]=true;
        for(auto a : mp[source]){
                if(!bus[a]){
                    bus[a] = true;
                    for(auto ch : routes[a]){
                        if(!busstop[ch]){
                            busstop[ch] = true;
                            pq.push({ch,1});
                        }
                    }
                }
            }
        while(!pq.empty()){
            auto it = pq.front();
            pq.pop();
            int stop = it.first;
            int level = it.second;
            cout<<stop<<endl;
            if(stop==target){
                return level;
            }
            for(auto a : mp[stop]){
                if(!bus[a]){
                    bus[a] = true;
                    for(auto ch : routes[a]){
                        if(!busstop[ch]){
                            busstop[ch] = true;
                            pq.push({ch,level+1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};