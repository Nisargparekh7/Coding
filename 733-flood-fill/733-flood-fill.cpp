class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int intital_color=image[sr][sc];
        if(intital_color !=color) dfs(image, sr, sc,intital_color, color);
        return image;
    }
    
    void dfs (vector<vector<int>>& image, int r, int c, int intital_color, int color){
        
        if(image[r][c]==intital_color){
            image[r][c]=color;
            
            if(r>0) dfs(image, r-1, c,intital_color, color);
            if(c>0) dfs(image, r, c-1,intital_color, color);
            if(r+1<image.size()) dfs(image, r+1, c,intital_color, color);
            if(c+1<image[0].size()) dfs(image, r, c+1,intital_color, color);
        }
    }
};