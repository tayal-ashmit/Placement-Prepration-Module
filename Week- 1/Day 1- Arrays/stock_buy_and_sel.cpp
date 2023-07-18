#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr, int n) {
    int maxi= 0;
    int mini= INT_MAX;

    for(int i=0; i<n; i++) {
        mini= min(mini, arr[i]);
        maxi= max(maxi, arr[i] - mini);
    }
    
    return maxi;
}

int main() {
    vector<int> arr= {7, 1, 5, 3, 6, 7, 5, 4};

    int maxi = maxProfit(arr, arr.size());

    cout<< "Max profit: "<< maxi;
    return 0;
}