#include<bits/stdc++.h>
using namespace std;

int longestSeq(vector<int> &arr) {
    set<int> s;
    for(int i: arr) {
        s.insert(i);
    }

    int maxi=0;
    for(int i: arr) {
        if(!s.count(i-1)) {
            int num = i;
            int streak = 1;

            while(s.count(num+1)) {
                num += 1;
                streak += 1;
            }

            maxi = max(maxi, streak);
        }
    }

    return maxi;
}

int main() {
    vector<int> arr{100, 200, 1, 2, 3, 4};
    int lon= longestSeq(arr);

    cout<< "The longest consecutive sequence is: "<< lon ;
    return 0;
}