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
    TreeNode* tree(vector<int> &preorder, int &i, int h) {
        if(i==preorder.size() || preorder[i]>h)
            return NULL;
        
        TreeNode* root= new TreeNode(preorder[i]);
        i++;

        root->left= tree(preorder, i, root->val);
        root->right= tree(preorder, i, h);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return tree(preorder, i, INT_MAX);
    }
};