class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if(root == NULL)
            return ans;

        map<int, int> m;
        queue<pair<Node*, int>> q;
        q.push({root, 0}); 

        while(!q.empty()) {
            auto i= q.front(); 
            q.pop(); 
            Node* node= i.first; 
            int line= i.second; 
            m[line]= node->data; 
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line+1}); 
            }
        }
        
        for(auto i : m) {
            ans.push_back(i.second); 
        }

        return ans;  
    }
};