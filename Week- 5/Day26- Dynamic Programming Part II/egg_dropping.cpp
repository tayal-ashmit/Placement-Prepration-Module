class Solution {
public:
    int eggDrop(int n, int k)  {
       vector<int> dp(n+1, 0);
        int moves= 0;
        while(dp[n] < k) {
            moves++;
            for(int i=n; i>0; i--)
                dp[i] += 1+dp[i-1];
        }
        
        return moves;
    }
};