class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int,int>m;
        int n = changed.size();
        if(n%2==1)
            return {};
        for(auto a : changed){
            m[a]++;
        }
        sort(changed.begin(),changed.end());
        vector<int>ans;
        for(int i =0; i<n; i++){
            if(m[changed[i]]>0){
                int it = changed[i]*2;
                if(m[it]>0){
                    ans.push_back(changed[i]);
                    m[changed[i]]--;
                    m[it]--;
                }
                else{
                return {};
            }
            }
            
        }
        return ans;
        
    }
};