class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n= matrix.size();
        int low=matrix[0][0]; int high=matrix[n-1][n-1];
        
        int mid;
        while(low<high){
            mid= low + (high-low)/2;
            
            int cnt=0;
            for(int i=0;i<n;i++){
                cnt+=upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if(cnt<k){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
        //priority_queue<int> pq;
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j< matrix[0].size();j++){
        //         if(pq.size()<k){
        //             pq.push(matrix[i][j]);
        //         }
        //         else if(matrix[i][j]>pq.top())continue;
        //         else{   
        //             pq.pop();
        //             pq.push(matrix[i][j]);
        //         } 
        //     }
        // }
        // return pq.top();
    }
};