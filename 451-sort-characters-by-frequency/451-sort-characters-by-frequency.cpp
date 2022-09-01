class Solution {
public:
    string frequencySort(string s) {
       unordered_map<char,int>m;
			int n = s.size();
			for(int i=0;i<n;i++)    m[s[i]]++;
			priority_queue<pair<int,char>> pq;
			for(auto i:m)    
                pq.push({i.second,i.first});
			string ans = "";
			while(!pq.empty())
			{
				for(int i=0;i<pq.top().first;i++)    
                    ans+=pq.top().second;
				pq.pop();
			}
			return ans;
    }
};