class Solution {
public:
    bool dfs(int node, int k, vector<int>& col, vector<int> adj[]) {
        col[node]= k;
        
        for(auto i: adj[node]) {
            if(col[i] == -1) {
                if(dfs(i, !k, col, adj) == false)
                    return false;
            }
            else if(col[i] == k)
                return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();

        vector<int> adj[n];
        for(int i=0; i<n; i++) {
            for(int j=0; j<graph[i].size(); j++) {
                adj[i].push_back(graph[i][j]);
            }
        }
        
        vector<int> col(n, -1);
        for(int i=0; i<n; i++) {
            if(col[i]==-1) {
                if(dfs(i, 0, col, adj) == false)
                    return false;
            }
        }
        return true;
    }
};