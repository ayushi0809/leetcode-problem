class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //vector<int>v = nums;
        int n = nums.size();
        for(int i =0; i<n; i++){
            nums.push_back(nums[i]);
        }
        stack<int>st;
        vector<int>ans;
        for(int i =2*n-1; i>=0; i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(-1); ;
            }
            else{
                ans.push_back(st.top());
               // ans[i] = st.top();
            }
            st.push(nums[i]);
        }
        vector<int>v;
        v.assign(ans.begin()+n , ans.end());
        reverse(v.begin(), v.end());
        return v;
    }
};