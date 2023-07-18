#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<vector<int>> &mat, int n, int m) {
    int row[n]= {0};
    int col[m]= {0};

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(row[i] || col[j]) {
                mat[i][j] = 0;
            }
        }
    }

    return mat;
}

int main() {
    vector<vector<int>> mat= {{1, 1, 1, 1}, 
                              {1, 0, 0, 1}, 
                              {1, 1, 1, 1},
                              {1, 0, 1, 1}};
    int n= mat.size();
    int m= mat[0].size();

    vector<vector<int>> ans = solve(mat, n, m);

    for(auto i: ans) {
        for(auto j: i) {
            cout<< j<< " ";
        }
        cout<< "\n";
    }

    return 0;
}