class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        int n= arr.size();
        vector<int> ans;

        unordered_map<int, int> m;
        for(int i=0; i<n; i++) {
            m[arr[i]]++;
        }
        
        priority_queue<pair<int, int>> q;
        for(auto i: m) {
            q.push({i.second, i.first});
        }

        int i=0;
        while(i<k) {
            ans.push_back(q.top().second);
            q.pop();
            i++;
        }

        return ans;
    }
};