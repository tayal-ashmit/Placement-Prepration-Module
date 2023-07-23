class Solution {
public:
    int strStr(string str, string s) {
        int m= str.length();
        int n= s.length();

        for(int i=0; i<=m-n; i++) {
            for(int j=0; j<n; j++) {
                if(s[j] != str[i+j])
                    break;
                if(j==n-1)
                    return i;
            }
        }
        
        return -1;
    }
};