#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> arr, int n) {
    int hash[n+1]= {0};

    for(int i=0; i<n; i++) {
        hash[arr[i]]++;
    }

    int repeating= -1;
    int missing= -1;

    for(int i=1; i<=n; i++) {
        if(hash[i] == 2)
            repeating = i;
        else if(hash[i] == 0) 
            missing = i;

        if(repeating != -1 && missing != -1)
            break;
    }
    return {repeating, missing};
}

int main() {
    vector<int> arr= {3, 1, 2, 5, 4, 6, 7, 5};

    vector<int> ans= solve(arr, arr.size());

    cout<< "Repeating number: "<< ans[0]<< endl;
    cout<< "Missing number:  "<< ans[1];

    return 0;
}