class Solution {
public:
    int numDistinct(string t, string s) {
        int n=t.size();
        int m= s.size();
        vector<vector<double>> dp(n+1,vector<double>(m+1,0));
    
        //tabulation
        
        //base case
        for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int j=1;j<=m;j++)dp[0][j]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(t[i-1]==s[j-1]){
                     dp[i][j]= dp[i-1][j-1] + dp[i-1][j];
                }
                else dp[i][j]=dp[i-1][j];   
            }
        }
        return dp[n][m];
    }
    
//     int f(string &t, string &s, int i, int j,vector<vector<int>> &dp){
//     if(j<0)return 1;
//     if(i<0)return 0;
    
//     if(dp[i][j]!=-1)return dp[i][j];
    
//     if(t[i]==s[j]){
//         return dp[i][j]= f(t,s,i-1,j-1,dp) + f(t,s,i-1,j,dp);
//     }
//     return dp[i][j]= f(t,s,i-1,j,dp);
// }
};