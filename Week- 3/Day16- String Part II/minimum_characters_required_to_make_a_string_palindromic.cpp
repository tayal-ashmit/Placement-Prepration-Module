int solve(string A) {
    int n= s.size();
    string s= A;
    reverse(A.begin(), A.end());
    s += '#' + A;

    vector<int> v(n, 0);
    for(int i=1; i<n; i++) {
        int j= v[i-1];
        while(j>0 && s[i] != s[j]) {
            j= v[j-1];
        }

        if(s[i] == s[j]) {
            j++;
        }
        v[i]=j;
    }
    
    return A.size() - v[n-1];
}