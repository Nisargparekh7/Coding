class Solution {
public:
//     int f(int ind, int prev_ind, vector<int>&nums,int n,vector<vector<int>>&dp){
//         //base case
//         if(ind==n)return 0;
        
//         if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];
//         //explore all possible
//         int len= 0+f(ind+1, prev_ind, nums,n,dp);
    
//         if(prev_ind==-1 || nums[ind]> nums[prev_ind]){
//             len=max(len, 1+f(ind+1, ind, nums,n,dp));
//         }
//         return dp[ind][prev_ind+1]=len;
        
//         }
    
    
    int lengthOfLIS(vector<int>& nums) {
       
        int n=nums.size();
        vector<int> dp(n,1), hash(n);
        int maxi=1;
        
        for(int i=0;i<n;i++){
            hash[i]=i;
            
            for(int prev=0;prev<i;prev++){
                
                if(nums[prev]<nums[i] && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
                
            }
            
            if(dp[i]>maxi){
            maxi=dp[i];
            }
      
        }
        
       return maxi;
        
    }
    
    
};