#include <bits/stdc++.h>
using namespace std;

string twoSum(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left=0;
    int right=n-1;

    while(left < right) {
        int sum= arr[left] + arr[right];

        if(sum == target) {
            return "YES";
        }
        else if(sum < target)
            left++;
        else
            right--;
    }
    return "NO";
}

int main() {
    vector<int> arr= {2, 6, 5, 8, 11};
    int target= 14;
    string ans= twoSum(arr.size(), arr, target);
    cout<< "2 sum possible: "<< ans ;
    return 0;
}