class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>m;
        for(auto a : magazine){
            m[a]++;
        }
        for(auto a : ransomNote){
            auto it = m.find(a);
                if(it==m.end()){
                    return false;
                }
              else if(it->second==0){
                  return false;
              }
            else{
                m[a]--;
            }
            
        
        }
        return true;
    }
};