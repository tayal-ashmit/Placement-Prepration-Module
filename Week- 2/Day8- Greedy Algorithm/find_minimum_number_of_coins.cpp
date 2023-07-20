#include<bits/stdc++.h>
using namespace std;

int main() {
    int v = 49;
    vector<int> ans;
    int coins[]= {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n= 9;
    for(int i=n-1; i>=0; i--) {
        while(v >= coins[i]) {
            v -= coins[i];
            ans.push_back(coins[i]);
        }
    }

    cout<< "The minimum number of coins is "<< ans.size()<< endl;
    cout<< "The coins are "<< endl;

    for(int i=0; i<ans.size(); i++) {
        cout<< ans[i]<< " ";
    }

    return 0;
}