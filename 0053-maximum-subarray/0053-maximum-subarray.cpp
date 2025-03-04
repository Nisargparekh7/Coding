class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=0;
        int n= nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            ans += nums[i];
            if (ans > maxi) maxi=ans;
            if(ans<0){
                ans =0;
            }
            
        }
        return maxi;
        
    }
};