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

class BST_Iterator {
public:
    stack<TreeNode*> s;
    bool rev= true;

    BST_Iterator(TreeNode* root, bool r) {
        rev= r;
        pushAll(root);
    }

    bool hasnext() {
        return !s.empty();
    }

    int next() {
        TreeNode* node= s.top();
        s.pop();
        if(rev==true)
            pushAll(node->left);
        else
            pushAll(node->right);
        
        return node->val;
    }

    void pushAll(TreeNode* node) {
        while(node!=NULL) {
            s.push(node);

            if(rev==true)
                node= node->right;
            else
                node= node->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
            return false;
        
        BST_Iterator l(root, false);
        BST_Iterator r(root, true);

        int i= l.next();
        int j= r.next();
        while(i<j) {
            if(i+j==k)
                return true;
            else if(i+j<k)
                i= l.next();
            else
                j= r.next();
        }
        return false;
    }
};