#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(vector<int> arr, int n) {
    long long maxi= LONG_MIN;
    long long sum= 0;

    for(int i=0; i<n; i++) {
        sum += arr[i];

        if(sum>maxi) {
            maxi = sum;
        }

        if(sum<0) {
            sum=0;
        }
    }

    return maxi;
}

int main() {
    vector<int> arr= {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    long long maxi= maxSubarraySum(arr, arr.size());
    
    cout<< "Maximum subarray sum: "<< maxi;
    return 0;
}