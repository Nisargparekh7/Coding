class Solution {
public:
    //other approch using recursion.
    void subset_sum(int index, vector<int>& nums, vector<vector<int>>& sum, vector<int>&temp){
        
        //basecase
        if(index==nums.size()) {
            if(std::find (sum.begin(), sum.end(), temp)== sum.end()) {
            sum.push_back(temp);    
            }

            return ;
        }
        
    //with element
      temp.push_back(nums[index]);
      subset_sum(index+1,nums,sum,temp);
      //removing taken element
      temp.pop_back();
      //without element
      subset_sum(index+1,nums,sum,temp);
       
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> sum;
        vector<int> temp;
        
        subset_sum(0,nums,sum,temp);

        return sum;
    }
};