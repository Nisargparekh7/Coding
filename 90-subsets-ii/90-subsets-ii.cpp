class Solution {
public:
    
    void subset_sum(int index, vector<int>& nums, vector<vector<int>>& sum, vector<int>&temp, int n){
        if(index==n) {
            if(std::find (sum.begin(), sum.end(), temp)== sum.end()) {
            sum.push_back(temp);    
            }
            
            return ;
        }
        
      temp.push_back(nums[index]);
     
      
      subset_sum(index+1,nums,sum,temp, n);
      
      temp.pop_back();
      
      subset_sum(index+1,nums,sum,temp,n);
       
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sum;
        int N= nums.size();
        
        vector<int> temp;
        subset_sum(0,nums,sum,temp,N);

        return sum;
    }
};