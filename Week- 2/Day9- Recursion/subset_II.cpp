class Solution {
  public:
    void solve(vector<vector<int>>& ans, vector<int>& arr, vector<int>& temp, int i) {
        ans.push_back(temp);

        for(int j=i; j<arr.size(); j++) {
            if(j!=i && arr[j]==arr[j-1])
                continue;
            
            temp.push_back(arr[j]);
            solve(ans, arr, temp, j+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(arr.begin(), arr.end());

        solve(ans, arr, temp, 0);
        
        return ans;
    }
};