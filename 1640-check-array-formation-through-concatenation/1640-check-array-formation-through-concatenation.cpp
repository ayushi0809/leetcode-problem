class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int,int>m;
        for(int i =0; i<arr.size();i++){
            m[arr[i]] = i;
        }
        for(int i =0; i<pieces.size(); i++){
            int index = INT_MIN;
            for(auto a : pieces[i]){
                if(m.find(a) == m.end()){
                    return false;
                }
                
                if(index != INT_MIN && m[a] != index+1){
                    return false;
                }
                index = m[a];
                //cout<<index<<endl;
            }
        }
        
        return true;
        
    }
};