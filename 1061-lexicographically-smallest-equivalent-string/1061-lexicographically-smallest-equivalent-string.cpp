class Solution {
public:
    void Union(int u, int v, vector<int>&mp){
        u = find(u,mp);
        v = find(v,mp);
        if(u==v)
            return;
       
            if(u<v){
                mp[v] = u;
            }
            else{
                mp[u] = v;
            }
        
    }
    int find(int u, vector<int>&mp){
       if(mp[u] == u){
           return u;
       }
        return mp[u] = find(mp[u],mp);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
       vector<int>mp(26,0);
        
        for(int i =0; i<26; i++){
            mp[i] = i;
        }
        
        for(auto it : s1){
            mp[it-'a'] = it-'a';
        }
        for(auto it : s2){
            mp[it-'a'] = it-'a';
        }
        
        int n = s1.size();
        
        for(int i =0; i<26; i++){
            cout<<char(i+97)<<" "<<char(mp[i]+97)<<endl;
        }
        for(int i =0; i<n; i++){
            Union(s1[i]-'a',s2[i]-'a',mp);
        }
        
        
        string ans = "";
        for(auto it : baseStr){
            int a = find(it-'a',mp);
            char ch = char(a+97);
            ans = ans+ch;
        }
        return ans;
        
    }
};