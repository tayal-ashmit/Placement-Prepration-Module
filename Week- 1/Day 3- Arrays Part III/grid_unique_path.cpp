#include<bits/stdc++.h>
using namespace std;

int countPaths(int i, int j, int n, int m) {
    if(i==n-1 && j==m-1)
        return 1;

    if(i>=n || j>=m)
        return 0;
    return countPaths(i+1, j, n, m) + countPaths(i, j+1, n, m);
}

int main() {
    int i=0, j=0;
    int ans= countPaths(i, j, 3, 7);

    cout<< "The total number of unique paths: "<< ans;
    return 0;
}