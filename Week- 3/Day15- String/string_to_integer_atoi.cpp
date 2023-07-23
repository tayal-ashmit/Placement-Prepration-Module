class Solution {
  public:
    int myAtoi(string s) {
        int n= s.length();
        bool negative= false;
        bool positive= false;
        
        int i=0;
        while(s[i] == ' ')
            i++;

        if(s[i] == '-') {
            negative= true;
            i++;
        }

        if(s[i] == '+') {
            positive=true;;
            i++;
        }

        double num=0;

        while(i<n && s[i]>='0' && s[i]<='9') {
            num= num*10+ (s[i]-'0');
            i++;
        }
        
        if(negative == true)
            num= -num;

        if(positive==true && negative==true)
            return 0;
        if(num < INT_MIN)
            return INT_MIN;
        if(num > INT_MAX)
            return INT_MAX;

        return (int)num;
    }
};