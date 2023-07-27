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
    class tree {
        public:
        int sum;
        int maxi;
        int mini;
        bool check;
    };

    tree solve(TreeNode* root, int &ans) {
        if(root==NULL) {
            return {0, INT_MIN, INT_MAX, true};
        }
        tree left= solve(root->left, ans);
        tree right= solve(root->right, ans);
        tree res;

        res.maxi= max(root->val, right.maxi);
        res.mini= min(root->val, left.mini);

        res.sum= root->val + left.sum + right.sum;
        res.check= false;
        if(left.check==true && right.check==true && root->val>left.maxi && root->val<right.mini) {
            res.check= true;
        }
        if(res.check==true) {
            ans= max(ans, res.sum);
        }
        return res;
    }

    int maxSumBST(TreeNode* root) {
        int ans= 0;
        solve(root, ans);
        return ans;
    }
};