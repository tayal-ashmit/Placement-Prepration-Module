class Solution {
  public:
    int repeatedStringMatch(string a, string b)  {
        int ans= 1;
        string temp= a; 
        while(a.size() < b.size()) {
            a += temp;
            ans++;  
        }

        int i= 0;
        int m= b.size() ;
        while(i <= a.size()-b.size()) {
            string temp= a.substr(i,m) ;
            if(temp==b)
                return ans;
            i++;
        }
        
        a += temp;
        while(i <= a.size()-b.size()) {
            string temp= a.substr(i,m) ;
            if(temp==b)
                return ans+1;
            i++;
        }

        return -1 ;
    }
};