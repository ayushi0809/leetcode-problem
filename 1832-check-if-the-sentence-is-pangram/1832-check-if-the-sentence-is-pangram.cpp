class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char>st;
        for(auto a: sentence){
            st.insert(a);
        }
        
        return st.size() == 26;
    }
};