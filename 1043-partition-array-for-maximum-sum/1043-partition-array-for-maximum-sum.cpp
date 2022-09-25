class Solution {
public:
    
    int f(int i, vector<int> &num, int k, vector<int>&dp){
        //base case
        int n=num.size();
        if(i==n)return 0;
        
        int len=0;
        int maxi=INT_MIN;
        int maxans=INT_MIN;
        if(dp[i]!=-1)return dp[i];
        
        for(int j=i;j<min(i+k,n);j++){
            len++;
            maxi=max(maxi, num[j]);
            int ans = len*maxi + f(j+1,num,k,dp);
            maxans=max(maxans, ans);
        }
        return dp[i]=maxans;
    }
    
    
    int maxSumAfterPartitioning(vector<int>& num, int k) {
        int n=num.size();
        vector<int>dp(n+1,-1);
        return f(0,num,k,dp);
    }
};