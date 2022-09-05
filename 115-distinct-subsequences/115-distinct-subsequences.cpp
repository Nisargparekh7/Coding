class Solution {
public:
    int numDistinct(string t, string s) {
        int n=t.size();
        int m= s.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(t,s,n-1,m-1,dp);
    }
    
    int f(string &t, string &s, int i, int j,vector<vector<int>> &dp){
    if(j<0)return 1;
    if(i<0)return 0;
    
    if(dp[i][j]!=-1)return dp[i][j];
    
    if(t[i]==s[j]){
        return dp[i][j]= f(t,s,i-1,j-1,dp) + f(t,s,i-1,j,dp);
    }
    return dp[i][j]= f(t,s,i-1,j,dp);
}
};