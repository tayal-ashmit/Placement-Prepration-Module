#include <bits/stdc++.h>
using namespace std;

vector<int> generate(int i) {
    long long ans=1;
    vector<int> row;
    row.push_back(1);

    for(int j=1; j<i; j++) {
        ans *= (i - j);
        ans /= j;
        row.push_back(ans);
    }
    return row;
}

int main() {
    int n=7;
    
    vector<vector<int>> ans;
    for(int i=1; i<=n; i++) {
        ans.push_back(generate(i));
    }

    for(auto i: ans) {
        for(auto j: i) {
            cout<< j<< " ";
        }
        cout<< "\n";
    }

    return 0;
}