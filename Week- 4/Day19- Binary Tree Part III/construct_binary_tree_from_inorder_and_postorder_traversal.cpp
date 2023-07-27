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
    TreeNode* maketree(vector<int> &postorder, int ps, int pe, vector<int> &inorder, int is, int ie, unordered_map<int, int> &m) {
        if(ps>pe || is>ie)
            return NULL;
        
        int x= postorder[pe];
        TreeNode* root= new TreeNode(x);
        
        int i=m[x];
        int rightnodes= ie-i;

        root->left= maketree(postorder, ps, pe-rightnodes-1, inorder, is, i-1, m);
        root->right= maketree(postorder, pe-rightnodes, pe-1, inorder, i+1, ie, m);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n= inorder.size();
        unordered_map<int, int> m;
        for(int i=0; i<n; i++) {
            m[inorder[i]]= i;
        }

        return maketree(postorder, 0, n-1, inorder, 0, n-1, m);
    }
};