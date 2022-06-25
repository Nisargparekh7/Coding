class Solution {
public:
     void subset_sum(int index, vector<int>& arr, vector<vector<int>>& sum,vector<int> &temp,int target){  
        if(target==0){
            sum.push_back(temp);
            return;
        }
         
        for(int i=index;i<arr.size();i++){
            
            if(i>index && arr[i]==arr[i-1])continue;
            
            if(arr[i]>target)break;
            
            temp.push_back(arr[i]);
            subset_sum(i+1,arr,sum,temp,target-arr[i]);
            temp.pop_back();
            
        }    

               
        }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> sum;
        vector<int> temp;
        //int ans=0;
        subset_sum(0,candidates,sum,temp,target);

        return sum;
    }
};