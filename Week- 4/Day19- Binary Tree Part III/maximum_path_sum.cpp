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
    int solve(TreeNode* root, int &m) {
        if(root==NULL)
            return 0;
        
        int l= max(0, solve(root->left, m));
        int r= max(0, solve(root->right, m));

        m= max(m, l+r+root->val);

        return max(l, r)+root->val;
    }

    int maxPathSum(TreeNode* root) {
        int m= INT_MIN;
        int k= solve(root, m);
        return m;
    }
};