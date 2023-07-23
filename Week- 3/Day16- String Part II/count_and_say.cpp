class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        if(n==1)
            return s;

        for(int i=2; i<=n; i++) {
            string x= "";
            int c= 1;
            int l= s.length();
            for(int j=1; j<l; j++) {
                if(s[j-1]==s[j]) {
                    c++;
                }
                else {
                    x += (to_string(c) + s[j-1]);
                    c=1;
                }
            }
            x += (to_string(c) + s[l-1]);
            s= x;
        }

        return s;
    }
};