class Solution {
public:
    void subset_sum(int index, vector<int>& arr, vector<vector<int>>& sum,vector<int> &temp, int n, int target){
            
        if(index==n){
            
            if(target==0){
                sum.push_back(temp);
                return;
            }
            else return;
            }
        
        if(arr[index]<=target){
        temp.push_back(arr[index]);
        subset_sum(index,arr,sum,temp,n,target-arr[index]);
        temp.pop_back();
       }
        subset_sum(index+1,arr,sum,temp,n,target);
               
        }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> sum;
        int N= candidates.size();
        vector<int> temp;
        int ans=0;
        subset_sum(0,candidates,sum,temp,N,target);

        return sum;

        
    }
};