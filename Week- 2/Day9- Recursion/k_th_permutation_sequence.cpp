#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        for(int i=1; i<n; i++) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans= "";
        k--;
        while(1) {
            ans += to_string(numbers[k / fact]);
            numbers.erase(numbers.begin()+k / fact);
            if(numbers.size() == 0) {
                break;
            }

            k %= fact;
            fact /= numbers.size();
        }
        return ans;
    }
};

int main() {
  int n=3;
  int k=3;

  Solution obj;
  string ans= obj.getPermutation(n, k);
  cout<< "The Kth permutation sequence is: "<< ans;

  return 0;
}