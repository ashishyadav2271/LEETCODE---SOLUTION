class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         int rows = image.size();
        int cols = image[0].size();
        int startColor = image[sr][sc];
        if (startColor == color) return image;
         function<void(int,int)> dfs = [&](int r, int c) {
            if (r < 0 || r >= rows || c < 0 || c >= cols) return;
             if (image[r][c] != startColor) return;
              image[r][c] = color;
              dfs(r+1, c); 
            dfs(r-1, c);
            dfs(r, c+1); 
            dfs(r, c-1);
             };
        dfs(sr, sc); 
        return image;
    }
};