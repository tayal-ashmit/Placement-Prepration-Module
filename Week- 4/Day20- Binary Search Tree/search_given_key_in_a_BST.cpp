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
    TreeNode* searchBST(TreeNode* root, int k) {
        if(root==NULL)
            return NULL;
        
        if(root->val==k)
            return root;
        
        TreeNode* l= searchBST(root->left, k);
        TreeNode* r= searchBST(root->right, k);

        if(l==NULL)
            return r;
        else
            return l;
    }
};