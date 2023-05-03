class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans;
        vector<int>v1;
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
        for(auto it : nums1){
            m1[it]++;
        }
        for(auto it : nums2){
            m2[it]++;
        }
        bool flag= false;
        for(auto it = m1.begin(); it != m1.end(); it++){
            if(m2.find(it->first) == m2.end()){
                v1.push_back(it->first);
            }
            
        }
        ans.push_back(v1);
        v1.clear();
        
        for(auto it = m2.begin(); it != m2.end(); it++){
             if(m1.find(it->first) == m1.end()){
                v1.push_back(it->first);
            }
            
        }
        ans.push_back(v1);
        
        return ans;
        
    }
};