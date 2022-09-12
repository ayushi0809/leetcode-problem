class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>frq;
        
        for(auto a : t){
            frq[a]++;
        }
        unordered_map<char,int>m;
        
        int i =0;
        int j =0;
        int required = frq.size();
        int current = 0;
        int count = INT_MAX;
        int n = s.size();
        string ans = "";
        int start; 
        int end;
        while(j<n){
            m[s[j]]++;
            if(frq.find(s[j]) != frq.end() && frq[s[j]] == m[s[j]]){
                current++;
            }
            while(current == required){
                if(j-i+1<count){
                    count = j-i+1;
                    start = i;
                    end = j;
                }
                //cout<<s[i]<<endl;
                m[s[i]]--;
            if(frq.find(s[i]) != frq.end() && frq[s[i]] > m[s[i]]){
                //cout<<"hehe"<<endl;
                current--;
            }
                    i++;
                }
            
            j++;
        }
        if(count != INT_MAX){
            ans = s.substr(start,count);
        }
        return ans;
        
    }
};