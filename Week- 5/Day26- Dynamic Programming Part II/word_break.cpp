class Solution {
public:
    bool wordBreakHelper(int i, string& s, unordered_set<string>& st, vector<int>& dp) {
        int n= s.size();
        dp[n]= 1;
        for(int i=n-1; i>=0; i--) {
            string temp;
            for(int j=i; j<s.size(); j++) {
                temp += s[j];
                if(st.find(temp) != st.end() && dp[j+1]) {
                    dp[i]= 1;
                    break;
                }
            }
        }
        return dp[0];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n= s.size();
        vector<int> dp(n+1, 0);

        return wordBreakHelper(0, s, st, dp);
    }
};