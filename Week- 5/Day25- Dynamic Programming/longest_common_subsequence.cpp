class Solution {
public:
    int solve(string &t1, string &t2, int i, int j, vector<vector<int>> &dp){
        if(i<0 || j<0)
            return 0;
        
        if(dp[i][j] == -1) {
            int res;

            if(t1[i] == t2[j])
                res= 1 + solve(t1, t2, i-1, j-1, dp);
            else
                res= max(solve(t1, t2, i-1, j, dp), solve(t1, t2, i, j-1, dp));

            dp[i][j]= res;
        }

        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1= text1.size();
        int n2= text2.size();

        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        return solve(text1, text2, n1-1, n2-1, dp);
    }
};