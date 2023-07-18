#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int> arr, int n) {
    unordered_map<int, int> m; 
    int maxi=0;
    int sum=0;

    for(int i=0; i<n; i++) {
        sum += arr[i]; 
        if(sum == 0) {
            maxi= i+1; 
        }
        else {
            if(m.find(sum) != m.end()) {
                maxi = max(maxi, i - m[sum]); 
            }
            else {
                m[sum] = i;
            }
        }   
    }

    return maxi; 
}

int main() {
    vector<int> arr= {9, -3, 3, -1, 6, -5};
    int n= arr.size();

    int ans= maxLen(arr, n);

    cout<< "Longest Subarray with zero sum: "<< ans;
    return 0;
} 