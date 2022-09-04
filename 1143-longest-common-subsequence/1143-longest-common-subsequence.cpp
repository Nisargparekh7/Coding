class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));

        //base case- using shifiting index\
        for(int ind2=0;ind2<=n2;ind2++)dp[0][ind2]=0;
        for(int ind1=0;ind1<=n1;ind1++)dp[ind1][0]=0;

         for(int ind1=1;ind1<=n1;ind1++){
           for(int ind2=1;ind2<=n2;ind2++){
               if(s[ind1-1]==t[ind2-1]) dp[ind1][ind2]= 1+ dp[ind1-1][ind2-1];

               else dp[ind1][ind2]= max(dp[ind1][ind2-1],dp[ind1-1][ind2]);

             }
         }
        //code for printing LCS
        int len=dp[n1][n2];
        string ans="";
        for(int i=0;i<len;i++)ans+='$';
        
        int index=len-1;
        int i=n1, j=n2;
        
        while(i>0 && j>0){
            if(s[i-1]==t[j-1]){
                ans[index]=s[i-1];
                index--;
                i--,j--;
            }
            else if(dp[i-1][j]> dp[i][j-1])i--;
            else j--;
        }
        cout<<ans;
        //till here 
        
        
        return dp[n1][n2];

}
    
};