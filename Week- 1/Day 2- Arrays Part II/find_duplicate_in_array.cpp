#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr, int n) {
    int freq[n+1]= {0};

    for(int i=0; i<n; i++) {
        if(freq[arr[i]] == 0) {
            freq[arr[i]]++;
        }
        else {
            return arr[i];
        }
    }

    return 0;
}

int main() {, 
    vector<int> arr= {1, 3, 4, 2, 3};
    int x= findDuplicate(arr, arr.size());

    cout<< "Duplicate element: " << x;
}