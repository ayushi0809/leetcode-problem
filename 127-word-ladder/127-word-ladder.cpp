class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wl) {
       int mini = INT_MAX;
        unordered_map<string,unordered_set<int>> adj;
        
        queue<pair<int,int>> q;
        q.push({wl.size(),0});
        while(!q.empty())
        {   
            string currw = "";
            pair<int,int> curr = q.front();   q.pop();
            int dis = curr.second;
            if(curr.first==wl.size())
                currw = beginWord;
            else
                currw = wl[curr.first];
            
            if(currw==endWord)
                mini = min(mini,dis);
            
            if(adj.find(currw)==adj.end())
            for(int i=0;i<wl.size();i++)
            {
                int diff = 0;
                for(int j=0;j<currw.size();j++)
                    if(currw[j]!=wl[i][j])
                        diff++;
                
                if(diff == 1)
                {
                    adj[currw].insert(i);
                    q.push({i,dis+1});
                }
            }
        }
        return mini==INT_MAX ? 0 : mini+1;
    }
};