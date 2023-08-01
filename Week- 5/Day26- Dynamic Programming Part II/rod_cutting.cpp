class Solution {
public:
    int solve(vector<vector<int>>& dp, int first, int last, vector<int>&cuts, int l, int r) {
        if(l>r)
            return 0;
        
        if(dp[l][r] != -1)
            return dp[l][r];
        
        int cost=INT_MAX;

        for(int i=l; i<=r; i++) {
            int lc= solve(dp, first, cuts[i], cuts, l, i-1);
            int rc= solve(dp, cuts[i], last, cuts, i+1, r);
            int k= (last-first) + lc + rc;
            cost= min(cost, k);
        }

        return dp[l][r] = cost;
    }

    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>> dp(101, vector<int>(101, -1));
        sort(cuts.begin(), cuts.end());

        return solve(dp, 0, n, cuts, 0, cuts.size()-1);
    }
};