class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m=grid.size();
        int n= grid[0].size();
        int days=0,total_mangoes=0,rotten_mangoes=0, cnt=0;
        queue<pair<int, int>> rotten;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0) total_mangoes++;
                if(grid[i][j]==2) rotten.push({i,j});
            }
        }
        //cout<< "total ="<< total_mangoes;
        //cout<< "rotten ="<< rotten.size();
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        while(!rotten.empty()){
            int k= rotten.size();
            cnt += k;
            while(k--){
                int x=rotten.front().first, y=rotten.front().second; 
                rotten.pop();
                // cout<< "x ="<< x<<" ";
                //     cout<< "y ="<< y<<" ";
                // cout<< endl;
                for(int i=0;i<4;i++){
                    int new_x= x+dx[i] , new_y= y+dy[i];
                    if(new_x<0 || new_y<0 || new_x>=m || new_y>=n || grid[new_x][new_y]!=1)continue;
                    grid[new_x][new_y]=2;
                    rotten.push({new_x,new_y});
                    // cout<< "x ="<< new_x<<" ";
                    // cout<< "y ="<< new_y<<" ";
                    // cout<< "size ="<< rotten.size()<<" ";
                    
                }
                   // cout<< endl<<endl;
            }
            if(!rotten.empty())days++;
        }
        // cout<< "cnt ="<< cnt;
        // cout<< "days = " << days;
        return  total_mangoes==cnt ? days : -1; 
    }
};