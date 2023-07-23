class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n= arr.size();
        multiset<int> m;
        vector<int> ans;

        for(int i=0; i<k; i++)
            m.insert(arr[i]);

        for (int i=k; i<n; i++) {
            int l= *(m.rbegin());

            m.insert(arr[i]);
            m.erase(m.find(arr[i-k]));
            ans.push_back(l);
        }

        int l= *(m.rbegin());
        ans.push_back(l);

        return ans;
    }
};