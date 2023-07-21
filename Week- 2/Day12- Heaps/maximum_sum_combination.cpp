vector<int> solve(vector<int> &A, vector<int> &B, int C) {
    int n= A.size();

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    priority_queue<pair<int, pair<int, int>>>pq;
    vector<int> ans;

    for(int i=0; i<n; i++) {
        pq.push({A[i]+B[n-1], {i, n-1}});
    }

    while(!pq.empty() && C--) {
        int vl= pq.top().first;
        int x= pq.top().second.first;
        int y= pq.top().second.second;
        pq.pop();

        ans.push_back(vl);
        if(y != 0)
            pq.push({A[x]+B[y-1], {x, y-1}});
    }
    return ans;
}