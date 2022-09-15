class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
           for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                }
            }
         }
    
        vector<int> dp2(n,1);
        for(int i=n-1;i>=0;i--){
           for(int prev=n-1;prev>i;prev--){
                if(nums[prev]<nums[i] && 1+dp2[prev]>dp2[i]){
                    dp2[i]=1+dp2[prev];
                }
            }
         }
        int maxi=0;
        for(int i=0;i<n;i++){
            if(dp[i] > 1 && dp2[i] > 1)
                maxi=max(maxi, dp[i]+ dp2[i]-1);
        }
       return n -maxi;
    }
};