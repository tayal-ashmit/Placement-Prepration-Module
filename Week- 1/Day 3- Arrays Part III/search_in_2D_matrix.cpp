#include <bits/stdc++.h>
using namespace std;

bool find(vector<vector<int>>& mat, int n, int m, int target) {
    if(n==0)
        return false;

    int lo=0;
    int hi=n*m-1;
    while(lo <= hi) {
        int mid= lo+(hi-lo)/2;

        if(mat[mid/m][mid % m] == target) {
            return true;
        }
        if(mat[mid/m][mid % m] < target) {
            lo= mid+1;
        }
        else {
            hi= mid-1;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> mat= {{1, 3, 5, 7},
                              {10, 11, 16, 20},
                              {23, 30, 34, 60}};
    
    int n=arr.size();
    int m=arr[0].size();
    int target= 30;

    cout<< "Element found: "<< find(mat, n, m, target);

    return 0;
}