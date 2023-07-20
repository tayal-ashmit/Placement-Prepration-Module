class Solution {
  public:
    void solve(vector<vector<int>> &ans, vector<int> &arr, vector<int> &temp, int i, int s, int k) {
        if(k==s) {
            ans.push_back(temp);
            return;
        }

        for(int j=i; j<arr.size(); j++) {
            if(j>i && arr[j]==arr[j-1])
                continue;
            
            if(s+arr[j] > k)
                break;

            temp.push_back(arr[j]);
            solve(ans, arr, temp, j+1, s+arr[j], k);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> temp;

        solve(ans, arr, temp, 0, 0, k);

        return ans;
    }
};