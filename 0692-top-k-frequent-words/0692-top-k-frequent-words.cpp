class Solution {
public:
    struct comparator
    {
        bool operator() (pair<int, string>& a, pair<int, string>& b)
        {
            if(a.first == b.first)           
            {
                return a.second < b.second;
            }
            else                            
            {
                return a.first > b.first;
            }
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>m;
        for(auto a : words){
            m[a]++;
        }
        
        priority_queue<pair<int,string>, vector<pair<int,string>>, comparator>pq;
        for(auto it = m.begin(); it != m.end(); it++){
            pq.push({it->second,it->first});
        }
        vector<string>ans;
        while(pq.size()-k>0){
            pq.pop();
        }
        while(pq.size()){
           ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};