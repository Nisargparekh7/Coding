class Solution {
public:
    void recursion_permute(int index,vector<int>&nums,vector<vector<int>>&ans){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            recursion_permute(index+1,nums,ans);
            swap(nums[index],nums[i]);
            }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        // vector<int> temp;
        // int freq[nums.size()];
        // for(int i=0;i<nums.size();i++) freq[i]=0;
        recursion_permute(0,nums, ans );
        return ans;
            
    }
};