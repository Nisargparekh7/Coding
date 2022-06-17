class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n= nums.size();
        if(n<3)return ans;
        for (int i=0;i<n;i++){
            int a= nums[i];
            int target= -a;
            int s=i+1;
            int e=n-1;
            while(s<e){
                //int temp = nums[s]+nums[e];
                if( nums[s]+nums[e]==target){
                    ans.push_back({nums[i],nums[s], nums[e]});
                     while(s<e && nums[s]==nums[s+1] )s++;
                     while( e-1>s && nums[e]==nums[e-1] )e--;
                    
                    s++;
                    e--;
                }
                else if ( nums[s]+nums[e]>target){
                    e--;
                }
                else{
                    s++;
                }
                // break;
            }
            while(i+1<n && nums[i]==nums[i+1] )i++;
        }
        return ans;
    }
};