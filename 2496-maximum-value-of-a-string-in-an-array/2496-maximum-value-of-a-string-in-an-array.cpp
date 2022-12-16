class Solution {
public:
    bool f(string st){
        for(auto ch : st){
            if(!isdigit(ch)){
                return false;
            }
        }
        return true;
    }
    int maximumValue(vector<string>& strs) {
        int maxi = INT_MIN;
        for(auto s : strs){
            if(f(s)){
                maxi = max(maxi, stoi(s));
            }
            else{
                int len = s.size();
                maxi = max(maxi, len);
            }
        }
        
        return maxi;
    }
};