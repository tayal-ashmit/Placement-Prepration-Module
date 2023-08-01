class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n= arr.size();
        unordered_map<int, int> m;

        for(int i=0; i<n; i++) {
            m[arr[i]]= 1;
            for(auto x: m) {
                if(x.first < arr[i]) {
                    m[arr[i]]= max(m[arr[i]], 1+x.second);
                }
            }
        }

        int maxi=0;
        for(auto i: m) {
            maxi= max(maxi, i.second);
        }

        return maxi;
    }
};