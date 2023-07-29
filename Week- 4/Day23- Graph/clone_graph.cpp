class Solution {
public:
    Node *clone(Node *node, unordered_map<Node*, Node*> &vis) {
        if(vis.find(node) != vis.end()) 
            return vis[node];

        Node *copy= new Node(node->val);
        vis[node]= copy;

        for(auto i: node->neighbors) {
            copy->neighbors.push_back(clone(i, vis));
        }

        return copy;
    }

    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        
        unordered_map<Node*, Node*> vis;
        return clone(node, vis);
    }
};