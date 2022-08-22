class Solution {
public:
    void recursion_permute(int index,vector<int>&nums,vector<vector<int>>&ans){
        //base case
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        
        //swaping every index with 1st position
        for(int i=index;i<nums.size();i++){
            //swapping
            swap(nums[index],nums[i]);
            
            //recusion call
            recursion_permute(index+1,nums,ans);
            
            //backtrack- as for 2nd time when loop runs we can swap with orinigal strings.
            swap(nums[index],nums[i]);
            }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        recursion_permute(0,nums, ans);
        return ans;
            
    }
};