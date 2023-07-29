class Solution {
  public:
    void dfs(int k, vector<int> adj[], int vis[], vector<int> &ans) {
        vis[k]=1;
        ans.push_back(k);
        
        for(auto i: adj[k]) {
            if(!vis[i]) {
                dfs(i, adj, vis, ans);
            }
        }
    }
    
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        vector<int> ans;
        int vis[v]= {0};
        dfs(0, adj, vis, ans);
        return ans;
    }
};