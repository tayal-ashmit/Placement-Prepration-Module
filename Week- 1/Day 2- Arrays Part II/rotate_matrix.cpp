#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &mat, int n) {
    for(int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
    
    for(int i=0; i<n; i++) {
        reverse(mat[i].begin(), mat[i].end());
    }
}

int main() {
    vector<vector<int>> arr= {{1, 2, 3},
                              {4, 5, 6},
                              {7, 8, 9}};
    
    int n= arr.size();
    int m= arr[0].size();
    rotate(arr, n);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout<< arr[i][j]<< " ";
        }
        cout << "\n";
    }

    return 0;
}