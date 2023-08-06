struct Node{
    Node* links[2];
    bool containskey(int bit) {
        return links[bit] != NULL;
    }
    void addbit(int bit, Node* node) {
        links[bit]= node;
    }
    Node* getnode(int bit) {
        return links[bit];
    }
};

class Trie{
public:
    Node* root;
    Trie() {
        root= new Node();
    }
    void insert(int num) {
        Node* node= root;
        for(int i=31; i>=0; i--){
            int bit= (num>>i) & 1;
            if(!node->containskey(bit)) {
                node->addbit(bit, new Node());
            }
            node= node->getnode(bit);
        }
    }
    int getmax(int num) {
        Node* node= root;
        int maxans= 0;
        for(int i=31; i>=0; i--) {
            int bit= (num>>i) &1;
            if(node->containskey(!bit)) {
                maxans= maxans|(1<<i);
                node= node->getnode(!bit);
            }
            else {
                node =node->getnode(bit);
            }
        }
        return maxans;
    }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n= nums.size();
        int ans=0;
        Trie* obj= new Trie();
        for(int i=0; i<n; i++){
            obj->insert(nums[i]);
        }
        
        for(int i=0; i<n; i++){
            ans=max(ans, obj->getmax(nums[i]));
        }
        return ans;
    }
};