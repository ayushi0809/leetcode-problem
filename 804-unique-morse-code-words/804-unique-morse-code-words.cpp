class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>v = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_map<string,int>m;
        
        for(int i =0; i<words.size(); i++){
            string s = words[i];
            string temp = "";
            for(auto a : s){
                temp = temp+v[a-'a'];
            }
            m[temp]++;
        }
        cout<<m.size()<<endl;
            return m.size();
    }
};