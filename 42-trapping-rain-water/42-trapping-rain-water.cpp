class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
       vector<int>maxleft(n);
        vector<int>maxright(n);
        
        int m = INT_MIN;
        for(int i =0; i<n; i++){
            m = max(m,height[i]);
            maxleft[i] = m;
        }
          m = INT_MIN;
        for(int i = n-1; i>=0; i--){
            m = max(m,height[i]);
            maxright[i] = m;
        }
        int ans = 0;
        for(int i =1; i<n-1; i++){
           
            ans = ans+min(maxleft[i], maxright[i]) - height[i];
            cout<<maxleft[i]<<" "<<maxright[i]<<endl;
        }
        
        return ans;
    }
};