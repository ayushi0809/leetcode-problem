class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        for(int i =0; i<nums1.size(); i++){
            m[nums1[i]] = i;
        }
        stack<int>st;
        vector<int>ans(nums1.size(),-1);
        for(int i =nums2.size()-1; i>=0; i--){
            cout<<nums2[i]<<endl;
           while(!st.empty() && nums2[st.top()]<= nums2[i]){
               st.pop();
           }
            auto it = m.find(nums2[i]);
            if( !st.empty() && it != m.end()){
                ans[it->second] = nums2[st.top()];
            }
            st.push(i);
        }
        return ans;
    }
};