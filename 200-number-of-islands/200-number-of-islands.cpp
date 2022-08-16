class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
               if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    ++cnt;
               }
            }
        }
        return cnt;
        
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        
        if(i< 0 || i>=grid.size() || j<0 || j>=grid[0].size()) return;
        
        if(grid[i][j]=='2' || grid[i][j]=='0') return;
        
        grid[i][j]='2';
        
        if( i+1<grid.size()) 
            dfs(grid,i+1,j);
        
        if( j-1>=0 ) 
            dfs(grid,i,j-1);
        
        if(i-1>=0 )
            dfs(grid,i-1,j);
        
        if( j+1<grid[0].size())
            dfs(grid,i,j+1);
        
    }
};