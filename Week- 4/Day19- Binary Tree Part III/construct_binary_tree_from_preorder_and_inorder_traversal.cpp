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
    TreeNode* maketree(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie, unordered_map<int, int> &m) {
        if(ps>pe || is>ie)
            return NULL;
        
        int x= preorder[ps];
        TreeNode* root= new TreeNode(x);

        int i= m[x];
        int leftnodes= i-is;

        root->left= maketree(preorder, ps+1, ps+leftnodes, inorder, is, i-1, m);
        root->right= maketree(preorder, ps+leftnodes+1, pe,  inorder, i+1, ie, m);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        int k=0;
        unordered_map<int, int> m;
        for(int i=0; i<n; i++) {
            m[inorder[i]]= i;
        }

        return maketree(preorder, 0, n-1, inorder, 0, n-1, m);
    }
};