#include <bits/stdc++.h> 
typedef pair<int, int> pii;

vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k) {
    vector<int>ans;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<int>indexes(k,0);
    for(int i=0; i<k; i++) {
        pq.push({kArrays[i][0], i});
    }

    while(!pq.empty()) {
        auto temp= pq.top();
        pq.pop();
        ans.push_back(temp.first);
        int ind= temp.second;
        int newIndex= indexes[ind]+1;
        if(newIndex < kArrays[ind].size()) {
            pq.push({kArrays[ind][newIndex], ind});
            indexes[ind]= newIndex;
        }
    }
    return ans;
}