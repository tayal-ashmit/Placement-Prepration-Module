#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int left= low;
    int right= mid+1;
    int c=0;

    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            c += (mid-left+1);
            right++;
        }
    }

    while(left <= mid) {
        temp.push_back(arr[left++]);
    }
    
    while(right <= high) {
        temp.push_back(arr[right++]);
    }

    for(int i=low; i<=high; i++) {
        arr[i]= temp[i-low];
    }

    return c;
}

int solve(vector<int> &arr, int low, int high) {
    int c=0;
    if(low >= high)
        return c;
    
    int mid= (low+high)/2 ;

    c += solve(arr, low, mid);
    c += solve(arr, mid+1, high);
    c += merge(arr, low, mid, high);

    return c;
}

int main() {
    vector<int> arr= {5, 4, 3, 2, 1};
    int n= arr.size();
    int c= solve(arr, 0, n-1);
    cout<< "The number of inversions are: "<< c;
    
    return 0;
}