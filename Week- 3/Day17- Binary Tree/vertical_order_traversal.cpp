/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void solve_levelorder(TreeNode* root, map<int, map<int, multiset<int>>> &m) {
        queue<pair<TreeNode*, pair<int, int>>> q;

        while(!q.empty()) {
            auto p= q.front();
            q.pop();

            TreeNode* node= p.first;
            int v=p.second.first;
            int l=p.second.second;

            m[v][l].insert(node->val);

            if(node->left)
                q.push({node->left, {v-1, l+1}});
            if(node->right)
                q.push({node->right, {v+1, l+1}});
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> m;

        solve_levelorder(root, m);
        
        vector<vector<int>> ans;
        for(auto i: m) {
            vector<int> temp;
            for(auto j: i.second) {
                temp.insert(temp.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};