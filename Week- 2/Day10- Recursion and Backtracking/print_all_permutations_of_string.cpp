class Solution {
public:
    void solve(int i, vector<vector<int>>& ans, vector<int>& arr) {
        if(i==arr.size()) {
            ans.push_back(arr);
            return;
        }
        
        for(int j=i; j<arr.size(); j++) {
            swap(arr[i], arr[j]);
            solve(i+1, ans, arr);
            swap(arr[i], arr[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& arr) {
        vector<vector<int>> ans;
        solve(0, ans, arr);
        
        return ans;
    }
};