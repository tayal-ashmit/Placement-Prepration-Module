class Solution {
    Node*succ(Node* root,int key){
        Node* temp= root;
        Node* ans= NULL;
       
        while(temp != NULL) {
            if(temp->key > key) {
               ans= temp;
               temp= temp->left;
            }
            else {
               temp= temp->right;
            }
        }
        return ans;
    }
   
    Node* pred(Node* root,int key){
        Node* temp= root;
        Node* ans= NULL;

        while(temp != NULL) {
            if(temp->key < key) {
               ans= temp;
               temp= temp->right;
            }
            else {
               temp= temp->left;
            }
        }
        return ans;
    }

    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        pre= pred(root, key);
        suc= succ(root, key);
    }
};