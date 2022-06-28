class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row= grid.size();
        int col = grid[0].size();
        int cnt=0;
        for (int i=0;i<row; i++){
            if(grid[i][0] < 0) cnt += grid[i].size();
            else if( grid[i][0]>=0 && grid[i][col-1]<0){
                int low =0,high=col-1,ans=0,mid ;
                int h=high;
                while(low<=high){
                    mid=(low+high)/2;
                    if(grid[i][mid]<0){
                        ans=mid;
                        high=mid-1;
                    }
                    else{
                        low=mid+1;
                    }
                } 
            // cout<<"cnt: "<<ans<<endl;
               cnt= cnt+ (h-ans+1);
            }
        }
        
        return cnt;
    }
};