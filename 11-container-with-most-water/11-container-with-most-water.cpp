class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i =0;
        int j = n-1;
        int maxarea =-1;
        while(i<j){
            maxarea = max(maxarea , min(height[i], height[j])*(j-i));
            if(height[i]>height[j])
                j--;
            else
                i++;
            
        }
        return maxarea;
        
    }
};