class Solution {
public:
    //recursion- same as Subset-1 problem. Just use set<vector> instead of vector of vector.
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> output;
        int index=0;
        sort(nums.begin(),nums.end());
        solve(nums, index, output, ans);
       
        //as we need to submit answer in vector<vector>.
        vector<vector<int>> a;
        for(auto it: ans){
            a.push_back(it);
        }
        return a;
    }
    
    void solve(vector<int> nums, int index, vector<int> output, set<vector<int>> &ans){
        
        //base case
        if(index>=nums.size()){
            ans.insert(output);
            return;
        }
        
        //recursion call without taking element
        solve(nums, index+1, output, ans);
        
        //recursion call with taking element
        output.push_back(nums[index]);
        solve(nums, index+1, output, ans);
    }
};