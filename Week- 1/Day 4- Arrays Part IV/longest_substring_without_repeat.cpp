#include <bits/stdc++.h>
using namespace std;

int solve(string str, int n) {
    if(n==0)
        return 0;

    int ans= INT_MIN;
    unordered_set<int> s;

    int l=0;
    for(int r=0; r<n; r++) {
        if(s.find(str[r]) != s.end()) {
            while(l<r && s.find(str[r]) != s.end()) {
                s.erase(str[l]);
                l++;
            }
        }
        s.insert(str[r]);
        ans = max(ans, r-l+1);
    }
    return ans;
}

int main() {
    string str= "ashmittayal";

    cout<< "The longest substring without repeating: "<<  solve(str, str.length());
    return 0;
}