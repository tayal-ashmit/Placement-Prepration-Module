class Solution {
  public:
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        vector<int> ans;
        vector<int> vis(v, 0);
        vis[0]=1;
        queue<int> q;
        q.push(0);
        
        while(!q.empty()) {
            int x= q.front();
            q.pop();
            for(auto i: adj[x]) {
                if(!vis[i]) {
                    vis[i]=1;
                    q.push(i);
                }
            }
            ans.push_back(x);
        }
        return ans;
    }
};