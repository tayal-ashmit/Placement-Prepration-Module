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
    TreeNode* tree(vector<int> &arr, int s, int e) {
        if(s>e)
            return NULL;
        
        int x= s+(e-s)/2;
        TreeNode* root= new TreeNode(arr[x]);

        root->left= tree(arr, s, x-1);
        root->right= tree(arr, x+1, e);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n= nums.size();
        return tree(nums, 0, n-1);
    }
};