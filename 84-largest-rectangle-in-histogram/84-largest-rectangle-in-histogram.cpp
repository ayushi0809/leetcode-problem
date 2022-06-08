class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int res = 0;
        int n = heights.size();
        //st.push(0);
        for(int i =0; i<=heights.size(); i++){
            while(!st.empty() &&(i==n || heights[st.top()]>=heights[i])){
                int h = heights[st.top()];
                st.pop();
                int w ;
                if(st.empty())
                   w =i;
                else
                    w =i-st.top()-1;
        res = max(res, w*h);
                }
            st.push(i);
            }
           
            
         return res;
        
    }
};