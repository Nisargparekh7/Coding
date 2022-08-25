class Solution {
public:
    // this approach is tabulation + space optimization.   
    
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) curr[j]=1;
                else{
                    int up=0,left=0;
                    if(i>0) up=prev[j];
                    if(j>0) left= curr[j-1];
                    curr[j]= up+left;
                }
            }
            prev=curr;
        }
        return prev[n-1];
    }
};

//you can refer all the approches on:: https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0