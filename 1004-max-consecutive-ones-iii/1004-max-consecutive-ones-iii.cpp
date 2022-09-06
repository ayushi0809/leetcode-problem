class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0;
        int maxi = INT_MIN;
        int i =0;
        queue<int>q;
        if(k==0){
            for( i =0; i<n; i++){
                if(nums[i] != 1){
            maxi = max(maxi,i-start);
            start = i+1;
            }
            }
        
         maxi = max(maxi, i-start);
        return maxi;
        }
        
    
    
        for( i =0; i<n; i++){
             if(nums[i] != 1){
                 if(k>0){
                     q.push(i);
                     k--;
                 }
                 else{
                 maxi = max(maxi, i-start);
                 start = q.front()+1;
                    q.pop();
                     q.push(i);
                     //k++;
                 }
             }
        }
        //cout<<start<<endl;
       
        maxi = max(maxi, i-start);
        return maxi;
        
    }
};