class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
     priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;  
        unordered_map<int,int>m;
        
        for(auto it : tasks){
            m[it]++;
        }
        for(auto &it : m){
            if(it.second<2){
                return -1;
            }
            pq.push({it.first,it.second});
        }
        int count =0;
        while(!pq.empty()){
            auto it = pq.top();
            cout<<it.first<<" "<<it.second<<endl;
            pq.pop();
            if(it.second<=3){
                //cout<<it.first<<endl;
                count++;
            }
            else{
                count++;
                pq.push({it.first,it.second-3});
            }
            
        }
        
        return count;
    }
};