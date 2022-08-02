class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
       priority_queue<int>pq;
        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                pq.push(matrix[i][j]);
            }
        }
        int i = n*n-k;
        while(i>0){
            pq.pop();
            i--;
        }
        cout<<pq.top()<<endl;
        return pq.top();
    }
};