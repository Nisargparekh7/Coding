class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j< matrix[0].size();j++){
                if(pq.size()<k){
                    pq.push(matrix[i][j]);
                }
                else if(matrix[i][j]>pq.top())continue;
                else{   
                    pq.pop();
                    pq.push(matrix[i][j]);
                } 
            }
        }
        return pq.top();
    }
};