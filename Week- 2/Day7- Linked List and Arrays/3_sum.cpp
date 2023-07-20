class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n= arr.size();
        sort(arr.begin(), arr.end());
        set<vector<int>> res;
        vector<vector<int>> ans;

        for(int i=0; i<n; i++) {
            int j= i+1;
            int k= n-1;
            while(j<k) {
                int s= arr[i]+arr[j]+arr[k];
                if(s==0) {
                    res.insert({arr[i], arr[j], arr[k]});
                    j++;
                    k--;
                }
                else if(s<0)
                    j++;
                else
                    k--;
            }
        }

        for(auto i : res)
            ans.push_back(i);

        return ans;
    }
};