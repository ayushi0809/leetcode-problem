class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(auto a : nums){
            m[a]++;
        }
        
        priority_queue<pair<int,int>>pq;
        
        for(auto it = m.begin(); it != m.end(); it++){
            pq.push({it->second, it->first});
        }
        vector<int>v;
        while(k && !pq.empty()){
            auto it = pq.top();
            pq.pop();
            k--;
            v.push_back(it.second);
        }
        
        return v;
        
    }
};