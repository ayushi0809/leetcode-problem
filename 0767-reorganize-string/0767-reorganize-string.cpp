class Solution {
public:
    struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        return a.second < b.second;
    }
};
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(auto it : s){
            mp[it]++;
        }
        priority_queue<pair<char,int>,vector<pair<char,int>>, myComp>pq;
        
        for(auto it = mp.begin(); it != mp.end(); it++){
            pq.push({it->first,it->second});
        }
        string ans = "";
        while(!pq.empty()){
            // cout<<pq.top().first<<" "<<pq.top().second<<endl;
            auto it = pq.top();
            pq.pop();
            if(ans.size() > 0 && ans[ans.size()-1] == it.first){
                if(pq.empty()){
                    return "";
                }
                else{
                    // cout<<pq.top().first<<" "<<pq.top().second<<" "<<"secondtime"<<endl;
                    auto it2 = pq.top();
                    pq.pop();
                    ans = ans+it2.first;
                    if(it2.second > 1){
                        pq.push({it2.first, --it2.second});
                    }
                    pq.push({it.first, it.second});
                }
            }
            else{
            ans = ans+it.first;
            if(it.second > 1){
                pq.push({it.first, --it.second});
            }
            }
             
            // pq.pop();
            
        }
        return ans;
        
    }
};