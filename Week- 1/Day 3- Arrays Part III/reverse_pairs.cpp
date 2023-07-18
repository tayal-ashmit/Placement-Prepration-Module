#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int> &arr, int n) {
    int c=0;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] > 2*arr[j])
                c++;
        }
    }

    return c;
}

int main() {
    vector<int> arr= {4, 1, 2, 3, 1};

    int c= countPairs(arr, arr.size());
    cout<< "The number of reverse pair are: " << c;
    
    return 0;
}