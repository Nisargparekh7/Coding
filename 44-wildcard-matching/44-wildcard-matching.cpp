class Solution {
public:
    bool f(int i,int j, string &s, string &p, vector<vector<int>> &dp){
        //base case
        if(i<0 && j<0)return true;
        if(i<0  && j>=0)return false;
        if(j<0 && i>=0){
            for(int x=0;x<=i;x++){
                if(s[x]!='*')return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        //explore all path
        
        if(s[i]==p[j] || s[i]=='?')return dp[i][j]=f(i-1,j-1, s,p,dp);
        
        if(s[i]=='*') return dp[i][j]=f(i-1,j, s,p,dp) | f(i,j-1, s,p,dp);
        
        return dp[i][j]=false; 
    }
    
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        
        vector<vector<int>> dp (m,vector<int>(n,-1));
        
        
        
        return f(m-1, n-1, p,s,dp);
    }
};


//for tablutaion
//  https://www.codingninjas.com/codestudio/problems/wildcard-pattern-matching_701650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1