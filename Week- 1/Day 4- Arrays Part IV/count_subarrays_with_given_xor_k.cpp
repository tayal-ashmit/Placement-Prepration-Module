#include <bits/stdc++.h>
using namespace std;

int count(vector<int> arr, int n, int k) {
    int x=0;
    map<int, int> m;
    m[x]++;
    int c=0;

    for(int i=0; i<n; i++) {
        x= x^arr[i];

        c += m[x^k];

        m[x]++;
    }
    return c;
}

int main() {
    vector<int> arr = {4, 2, 2, 6, 4};
    int k=6;

    int ans= count(arr, arr.size(), k);
    
    cout<< "The number of subarrays with XOR k is: "<< ans;
    return 0;
}