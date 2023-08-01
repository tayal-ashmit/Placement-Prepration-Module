class Solution {
public:
    int solve(int amount, vector<int>& coins,vector<int>& dp) {
        if(amount<0)
            return 1e6;
        if(amount==0)
            return 0;
        if(dp[amount]!=-1)
            return dp[amount];

        int mini= 1e6;
        for(int i=0; i<coins.size(); i++) {
            int ans= solve(amount-coins[i], coins, dp);
            if(ans!=1e6)
                mini= min(mini, ans+1);
        }
        
        return dp[amount]= mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int ans= solve(amount, coins, dp);

        return ans<1e6 ? ans : -1;
    }
};