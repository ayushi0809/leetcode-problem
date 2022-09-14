class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        int n = tasks.size();
        
        if(k==0)
            return n;
        
        unordered_map<char,int>m;
        
        for(auto a : tasks){
            m[a]++;
        }
        
        priority_queue<int>pq;
        
        for(auto it = m.begin(); it != m.end(); it++){
            pq.push(it->second);
        }
        
        deque<pair<int,int>>dq;
        int count =0;
        while(!pq.empty() || !dq.empty()){
            count++;
            if(!pq.empty()){
                int it = pq.top()-1;
                pq.pop();
                if(it>0){
                    dq.push_back({it,count+k});
                }
                
            }
            if(!dq.empty() && dq.front().second==count){
                pq.push(dq.front().first);
                dq.pop_front();
            }
        }
        
        return count;
        
    }
};