class Solution {
public:
    
    //using tabulation with space optimization
    int climbStairs(int n) {
        // here a=1 & b=1 (unlike of fibonacci number);
        int a=1,b=1;
        //if i=1 return 1. i.e c is intialized with 1;
        int c=1;
        
        for(int i=2;i<=n;i++){
            c= a+b;
            a=b;
            b=c;
        }
        return c;
        
    }
    
    
    
    
    
    //using memoization
    // int climbStairs(int n) {
    //     vector<int> dp(n+1,-1);
    //     return climb(n,dp);
    // }
    // int climb(int n, vector<int> &dp){
    //     if(n==0 || n==1)return 1;
    //     if(dp[n]!= -1) return dp[n];
    //     return dp[n]=climb(n-1,dp)+ climb(n-2,dp);
    // }
};