class Solution {
public:
    string frequencySort(string s) {
       unordered_map<char,int>freq;
			int n = s.size();
			for(int i=0;i<n;i++)    freq[s[i]]++;
			priority_queue<pair<int,char>> maxH;
			for(auto i:freq)    maxH.push({i.second,i.first});
			string ans;
			while(!maxH.empty())
			{
				for(int i=0;i<maxH.top().first;i++)    ans+=maxH.top().second;
				maxH.pop();
			}
			return ans;
    }
};