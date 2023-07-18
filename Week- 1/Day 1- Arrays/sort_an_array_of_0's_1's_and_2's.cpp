#include <bits/stdc++.h>
using namespace std;

void sortArr(vector<int>& arr, int n) {
    int low= 0;
    int mid= 0;
    int high= n-1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    vector<int> arr= {0, 2, 1, 2, 0, 1, 0, 0, 1, 2, 0, 1};

    sortArr(arr, arr.size());
    
    for(int i: arr) {
        cout<< i<< " ";
    }

    return 0;
}