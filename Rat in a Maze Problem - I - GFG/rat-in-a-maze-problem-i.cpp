// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    void next(int row, int col, vector<vector<int>>&m, int n,  vector<string> &ans,string move,vector<vector<int>> &vis){
        if(row==n-1 && col==n-1){
            ans.push_back(move);
            return;
        }
        
        if(row+1<n && !vis[row+1][col] && m[row+1][col] == 1 ){
            vis[row][col]=1;
            next(row+1,col,m,n,ans,move+'D',vis);
            vis[row][col]=0;
        }
        if( col-1>=0 && !vis[row][col-1] && m[row][col-1] == 1 ){
            vis[row][col]=1;
            next(row,col-1,m,n,ans,move+'L',vis);
            vis[row][col]=0;
        }
        
        if( col+1 <n && !vis[row][col+1] && m[row][col+1] == 1 ){
            vis[row][col]=1;
            next(row,col+1,m,n,ans,move+'R',vis);
            vis[row][col]=0;
        }
        if( row-1>=0 && !vis[row-1][col] && m[row-1][col] == 1 ){
            vis[row][col]=1;
            next(row-1,col,m,n,ans,move+'U',vis);
            vis[row][col]=0;
        }
        //else return false;
    }
    
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        //vector<vector<int>> ans, 
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n,0));
        if(m[0][0]==1)next(0,0,m,n, ans,"", vis);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends