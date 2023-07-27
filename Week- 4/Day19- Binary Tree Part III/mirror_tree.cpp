class Solution {
    void mirror(Node* root) {
        if(root==NULL) {
            return;
        }
        
        Node* left1= root->left;
        Node* right1= root->right;
        
        root->left= right1;
        root->right= left1;

        mirror(root->left);
        mirror(root->right);
    }
}