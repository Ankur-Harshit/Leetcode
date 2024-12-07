class Solution {
    public:
    void dfs(int row, int col, int color, int c, vector<vector<int>> &image, 
    vector<vector<int>> &vis){
        int m = image.size();
        int n = image[0].size();
        image[row][col] = color;
        vis[row][col] = 1;
        int crow[] = {-1,1,0,0};
        int ccol[] = {0,0,-1,1};

        for(int i=0;i<4;i++){
            int nrow = row+crow[i];
            int ncol = col+ccol[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && 
            image[nrow][ncol]==c && vis[nrow][ncol]==0){
                dfs(nrow,ncol,color,c,image,vis);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int c = image[sr][sc];
        vector<vector<int>> vis(m,vector<int>(n,0));
        dfs(sr,sc,color,c,image,vis);
        return image;
    }
};
