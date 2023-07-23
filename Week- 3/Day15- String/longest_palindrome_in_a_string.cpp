class Solution {
  public:
    string longestPalindrome(string s) {
        int n= s.length();

        int start= 0;
        int maxLen= 1;

        for(int i=1; i<n; i++) {
            int left= i;
            int right= i;
            while(left >= 0 && right < n && s[left] == s[right]) {
                int currLen= right-left+1;
                if(currLen > maxLen) {
                    maxLen= currLen;
                    start= left;
                }
                left--;
                right++;
            }

            left= i-1;
            right= i;
            while(left >= 0 && right < n && s[left] == s[right]) {
                int currLen= right-left+1;
                if(currLen > maxLen) {
                    maxLen= currLen;
                    start= left;
                }
                left--;
                right++;
            }
        }

        return s.substr(start, maxLen);

    }
};