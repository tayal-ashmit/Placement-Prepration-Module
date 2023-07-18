#include <bits/stdc++.h>
using namespace std;

void merge(vector<long long> &arr1, vector<long long> &arr2, int n, int m) {
    int left= 0;
    int right= 0;
    int index= 0;
    vector<long long> arr3(n+m);

    while(left < n && right < m) {
        if(arr1[left] <= arr2[right]) {
            arr3[index++] = arr1[left++];
        }
        else {
            arr3[index++] = arr2[right++];
        }
    }

    while(left < n) {
        arr3[index++] = arr1[left++];
    }

    while(right < m) {
        arr3[index++] = arr2[right++];
    }

    for(int i=0; i<n+m; i++) {
        if(i<n)
            arr1[i] = arr3[i];
        else
            arr2[i-n] = arr3[i];
    }
}

int main() {
    vector<long long> arr1= {1, 15, 8, 10, 9};
    vector<long long> arr2= {2, 3, 9, 5, 4};
    int n= arr1.size();
    int m= arr2.size();

    merge(arr1, arr2, n, m);

    for(int i: arr1) {
        cout<< i<< " ";
    }
    cout<< endl;
    for(int i: arr2) {
        cout<< i<< " ";
    }
    
    return 0;
}