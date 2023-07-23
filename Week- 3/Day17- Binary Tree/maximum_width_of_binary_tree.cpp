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
    int widthOfBinaryTree(TreeNode* root) {
        int ans= 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()) {
            int s= q.size();
            int m= q.front().second;
            int first, last;
            
            for(int i=0; i<s; i++) {
                TreeNode* node= q.front().first;
                long long c= q.front().second-m;
                q.pop();

                if(i==0)
                    first=c;
                if(i==s-1)
                    last=c;
                
                if(node->left)
                    q.push({node->left, 2*c+1});
                if(node->right)
                    q.push({node->right, 2*c+2});
            }
            ans= max(ans, last-first+1);
        }
        
        return ans;
    }
};