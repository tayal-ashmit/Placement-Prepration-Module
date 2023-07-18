#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(int n, vector<int>& arr, int target) {
    set<vector<int>> s;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            set<long long> st;

            for(int k=j+1; k<n; k++) {
                long long sum= arr[i] + arr[j] + arr[k];
                long long x = target - sum;

                if(st.find(x) != st.end()) {
                    vector<int> v= {arr[i], arr[j], arr[k], (int)(x)};
                    sort(v.begin(), v.end());
                    s.insert(v);
                }
                
                st.insert(arr[k]);
            }
        }
    }

    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

int main() {
    vector<int> arr= {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target= 9;
    vector<vector<int>> ans= fourSum(arr.size(), arr, target);

    cout<< "The quadruplets are: \n";
    for(auto i : ans) {
        cout<< "[";
        for(auto j: i) {
            cout<< j<< " ";
        }
        cout<< "] "<< endl;
    }

    return 0;
}
