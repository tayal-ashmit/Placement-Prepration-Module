class Solution {
public:
    void dfs(vector<vector<char>>& arr, int i, int j, int n, int m) {
        if(i<0 || i>=n || j<0 || j>=m || arr[i][j]!='1')
            return;
        
        arr[i][j]='0';
        
        dfs(arr, i-1, j, n, m);
        dfs(arr, i+1, j, n, m);
        dfs(arr, i, j-1, n, m);
        dfs(arr, i, j+1, n, m);
    }
    
    int numIslands(vector<vector<char>>& arr) {
        int n= arr.size();
        int m= arr[0].size();
        int c=0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(arr[i][j]=='1') {
                    dfs(arr, i, j, n, m);
                    c++;
                }
            }
        }
        return c;
    }
};