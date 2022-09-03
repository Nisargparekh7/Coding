class Solution {
public:
    
//     int f(int n, vector<int> &num, int x,vector<vector<int>> dp){
//         //base case
//         if(n==0){
//             if(x%num[0]==0)return x/num[0];
//             else return 1e9;
//         }
//         if(dp[n][x]!=-1)return dp[n][x]; 
//         int nottake=f(n-1,num,x,dp);
//         int take=INT_MAX;
//         if(num[n]<=x)take= 1+f(n,num,x-num[n],dp);
//         return dp[n][x]=min(take,nottake);
//     }
    
    int coinChange(vector<int>& num, int x) {
        
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(x+1,0));
    //basecae
    for(int i=0;i<=x;i++){
        if(i%num[0]==0)dp[0][i]=i/num[0];
        else dp[0][i]=1e9;
    }
   for(int ind=1;ind<n;ind++){
       for(int T=0;T<=x;T++){
           int nottake=dp[ind-1][T];
           int take=INT_MAX;
           if(num[ind]<=T)take= 1+dp[ind][T-num[ind]];
           dp[ind][T]=min(take,nottake);
       }
   }
    int ans=dp[n-1][x] ;
    
    if(ans>=1e9)return -1;
   
    return ans ;
    }
};