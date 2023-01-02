class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int count =0;
        for(auto it : word){
            if(int(it) >= 65 && int(it) <= 90){
                count++;
            }
        }
        
        if(count == word.size() || count ==0 || (count == 1 && int(word[0]) >= 65 && int(word[0]) <= 90)){
            return true;
        }
        
        return false;
        
    }
};