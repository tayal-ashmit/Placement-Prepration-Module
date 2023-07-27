/*
A binary tree Node
struct Node {
    int data;
    Node* left, * right;
};
*/

class Solution {
public:
    bool isleaf(Node* root) {
        if(root->left==NULL && root->right==NULL)
            return true;
        return false;
    }
    
    void leftboundary(Node* root, vector<int> &ans) {
        Node* node= root->left;
        while(node) {
            if(!isleaf(node))
                ans.push_back(node->data);
            if(node->left)
                node= node->left;
            else
                node= node->right;
        }
    }
    
    void leaves(Node* root, vector<int> &ans) {
        if(isleaf(root)) {
            ans.push_back(root->data);
            return;
        }
        if(root->left)
            leaves(root->left, ans);
        if(root->right)
            leaves(root->right, ans);
    }
    
    void rightboundary(Node* root, vector<int> &ans) {
        Node* node= root->right;
        vector<int> temp;
        while(node) {
            if(!isleaf(node))
                temp.push_back(node->data);
            if(node->right)
                node= node->right;
            else
                node= node->left;
        }
        for(int i=temp.size()-1; i>=0; i--)
            ans.push_back(temp[i]);
    }
    
    vector <int> boundary(Node *root) {
        vector<int> ans;
        
        if(root==NULL)
            return ans;
        
        if( !isleaf(root))
            ans.push_back(root->data);
        
        leftboundary(root, ans);
        leaves(root, ans);
        rightboundary(root, ans);
        
        return ans;
    }
};