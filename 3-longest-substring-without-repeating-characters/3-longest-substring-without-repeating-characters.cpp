class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>us;
        int m = INT_MIN;
        int si;
        int start =0;
        for(int i =0;i<s.size(); i++){
            if(us.find(s[i]) != us.end()){
                 si = us.size();
                m = max(m, si);
                //us.clear();
                //cout<<m<<endl;
                auto it = us.find(s[i]);
                int t = it->second;
                cout<<t<<endl;
                while(start<=t){
                    us.erase(s[start]);
                    start++;
                }
            }
            us.insert({s[i],i});
        }
        si = us.size();
        //cout<<si<<endl;
        m = max(m,si);
     return m;   
    }
};