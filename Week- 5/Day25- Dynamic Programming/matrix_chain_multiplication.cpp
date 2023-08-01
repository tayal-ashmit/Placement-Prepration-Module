class Solution{
public:
    int solve(int i, int j, vector<int>&arr, vector<vector<int>> &dp) {
        if(i==j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=1e9;
        for(int k=i; k<j; k++) {
            int step= arr[i-1]*arr[k]*arr[j] + solve(i, k, arr, dp) + solve(k+1, j, arr, dp);
            ans=min(ans, step);
        }
        
        return dp[i][j]=ans;
    }

    int matrixMultiplication(int n, int arr[]) {
        vector<int> v(n);
        for(int i=0; i<n; i++)
            v[i]= arr[i];
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return solve(1, n-1, v, dp);
    }
};