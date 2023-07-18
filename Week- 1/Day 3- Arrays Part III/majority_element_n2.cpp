#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v, int n) {
    map<int, int> m;
    for(int i=0; i<n; i++) {
        m[v[i]]++;
    }

    for(auto i: m) {
        if(i.second > n/2)
            return i.first;
    }

    return -1;
}

int main() {
    vector<int> arr= {2, 2, 1, 1, 1, 2, 2};
    int ans= majorityElement(arr, arr.size());

    cout<< "Majority element: "<< ans;
    return 0;
}