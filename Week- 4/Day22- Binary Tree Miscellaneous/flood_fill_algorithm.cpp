class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int x, vector<vector<int>> &vis, int n, int m) {
        if(sr<0 || sr>=n || sc<0 || sc>=m || image[sr][sc]!=x || vis[sr][sc]==1)
            return;

        vis[sr][sc]=1;
        image[sr][sc]=color;

        dfs(image, sr-1, sc, color, x, vis, n, m);
        dfs(image, sr+1, sc, color, x, vis, n, m);            
        dfs(image, sr, sc-1, color, x, vis, n, m);
        dfs(image, sr, sc+1, color, x, vis, n, m);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int x=image[sr][sc];
        dfs(image, sr, sc, color, x, vis, n, m);

        return image;
    }
};