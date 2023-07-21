class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        int n= arr.size();
        priority_queue<int> q;
        for(int i=0; i<n; i++) {
            q.push(arr[i]);
        }

        int i=0;
        while(i<k-1) {
            q.pop();
            i++;
        }
        return q.top();
    }
};