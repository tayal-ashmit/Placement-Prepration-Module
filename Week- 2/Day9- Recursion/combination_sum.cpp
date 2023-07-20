class Solution {
  public:
    void solve(vector<vector<int>> &ans, vector<int> &arr, vector<int> &temp, int i, int s, int k) {
        if(i==arr.size()) {
            if(k==s)
                ans.push_back(temp);
            return;
        }

        if(s+arr[i] <= k) {
            temp.push_back(arr[i]);
            solve(ans, arr, temp, i, s+arr[i], k);
            temp.pop_back();
        }

        solve(ans, arr, temp, i+1, s, k);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int k) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(ans, arr, temp, 0, 0, k);

        return ans;
    }
};